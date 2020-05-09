#include "HttpMessage.h"
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <iostream>
#include "Channel.h"
#include "EventLoop.h"
#include "Util.h"

using namespace std;


const int DEFAULT_EVENT = EPOLLIN | EPOLLET | EPOLLONESHOT;
const int DEFAULT_EXPIRED_TIME = 2000;              // ms
const int DEFAULT_KEEP_ALIVE_TIME = 5 * 60 * 1000;  // ms

std::unordered_map<std::string, std::string> HttpMessage::type = {
        {".html",  "text/html"},
        {".xml",   "text/xml"},
        {".xhtml", "application/xhtml+xml"},
        {".txt",   "text/plain"},
        {".rtf",   "application/rtf"},
        {".pdf",   "application/pdf"},
        {".word",  "application/nsword"},
        {".png",   "image/png"},
        {".gif",   "image/gif"},
        {".jpg",   "image/jpeg"},
        {".jpeg",  "image/jpeg"},
        {".au",    "audio/basic"},
        {".mpeg",  "video/mpeg"},
        {".mpg",   "video/mpeg"},
        {".avi",   "video/x-msvideo"},
        {".gz",    "application/x-gzip"},
        {".tar",   "application/x-tar"},
        {".css",   "text/css"}
};

std::string HttpMessage::getType(const std::string &suffix) {
    if (type.find(suffix) == type.end()) return type["default"];
    else return type[suffix];
}

HttpMessage::HttpMessage(EventLoop *loop, int connfd)
        : loop_(loop),
          channel_(new Channel(loop, connfd)),
          fd_(connfd),
          error_(false),
          connectionState_(H_CONNECTED),
          method_(METHOD_GET),
          version_(HTTP_11),
          state_(STATE_PARSE_URI),
          keepAlive_(false) {
    channel_->setReadHandler([this] { handleRead(); });
    channel_->setWriteHandler([this] { handleWrite(); });
    channel_->setConHandler([this] { handleConn(); });
}

void HttpMessage::reset() {
    fileName_.clear();
    path_.clear();
    state_ = STATE_PARSE_URI;
    headers_.clear();
    resetTimer();
}

void HttpMessage::resetTimer() {
    if (timer_.lock()) {
        shared_ptr<TimerNode> my_timer(timer_.lock());
        my_timer->clearReq();
        timer_.reset();
    }
}

void HttpMessage::handleRead() {
    unsigned int &events_ = channel_->getEvents();
    bool zero = false;
    int read_num = readn(fd_, inBuffer_, zero);
    LOG << "Request: " << inBuffer_;
    if (connectionState_ == H_DISCONNECTING) {
        inBuffer_.clear();
        events_ |= EPOLLIN;
        return;
    }
    if (read_num < 0) {
        perror("1");
        error_ = true;
        handleError(fd_, 400, "Bad Request");
        return;
    } else if (zero) {
        // 有请求出现但是读不到数据，可能是Request
        // Aborted，或者来自网络的数据没有达到等原因
        // 最可能是对端已经关闭了，统一按照对端已经关闭处理
        // error_ = true;
        connectionState_ = H_DISCONNECTING;
        if (read_num == 0) {
            error_ = true;
            return;
        }
    }
    while (1) {
        if (state_ == STATE_PARSE_URI) {
            URIState flag = this->parseURI();
            if (flag == PARSE_URI_AGAIN) break;
            else if (flag == PARSE_URI_ERROR) {
                perror("2");
                LOG << "FD = " << fd_ << "," << inBuffer_ << "******";
                inBuffer_.clear();
                error_ = true;
                handleError(fd_, 400, "Bad Request");
                break;
            } else state_ = STATE_PARSE_HEADERS;
        }
        if (state_ == STATE_PARSE_HEADERS) {
            HeaderState flag = this->parseHeaders();
            if (flag == PARSE_HEADER_ERROR) {
                perror("3");
                error_ = true;
                handleError(fd_, 400, "Bad Request");
                break;
            }
            if (method_ == METHOD_POST) {
                // POST方法准备
                state_ = STATE_RECV_BODY;
            } else {
                state_ = STATE_ANALYSIS;
            }
        }
        if (state_ == STATE_RECV_BODY) {
            int content_length = -1;
            if (headers_.find("Content-Length") != headers_.end()) {
                content_length = stoi(headers_["Content-Length"]);
            } else {
                error_ = true;
                handleError(fd_, 400, "Bad Request: Lack of argument (Content-Length)");
                break;
            }
            if (static_cast<int>(inBuffer_.size()) < content_length) break;
            state_ = STATE_ANALYSIS;
        }
        if (state_ == STATE_ANALYSIS) {
            AnalysisState flag = this->analysisRequest();
            if (flag == ANALYSIS_SUCCESS) {
                state_ = STATE_FINISH;
                break;
            } else {
                error_ = true;
                break;
            }
        }
    }
    if (!error_) {
        if (!outBuffer_.empty()) {
            handleWrite();
        }
        if (!error_ && state_ == STATE_FINISH) {
            this->reset();
            if (!inBuffer_.empty()) {
                if (connectionState_ != H_DISCONNECTING) handleRead();
            }
        } else if (!error_ && connectionState_ != H_DISCONNECTED)
            events_ |= EPOLLIN;
    }
}

void HttpMessage::handleWrite() {
    if (!error_ && connectionState_ != H_DISCONNECTED) {
        unsigned int &events_ = channel_->getEvents();
        if (writen(fd_, outBuffer_) < 0) {
            perror("writen");
            events_ = 0;
            error_ = true;
        }
        if (!outBuffer_.empty()) events_ |= EPOLLOUT;
    }
}

void HttpMessage::handleConn() {
    resetTimer();
    unsigned int &events_ = channel_->getEvents();
    if (!error_ && connectionState_ == H_CONNECTED) {
        if (events_ != 0) {
            int timeout = DEFAULT_EXPIRED_TIME;
            if (keepAlive_) timeout = DEFAULT_KEEP_ALIVE_TIME;
            if ((events_ & EPOLLIN) && (events_ & EPOLLOUT)) {
                events_ = int(0);
                events_ |= EPOLLOUT;
            }
            events_ |= EPOLLET;
            loop_->updatePoller(channel_, timeout);

        } else if (keepAlive_) {
            events_ |= (EPOLLIN | EPOLLET);
            int timeout = DEFAULT_KEEP_ALIVE_TIME;
            loop_->updatePoller(channel_, timeout);
        } else {
            events_ |= (EPOLLIN | EPOLLET);
            int timeout = (DEFAULT_KEEP_ALIVE_TIME >> 1);
            loop_->updatePoller(channel_, timeout);
        }
    } else if (!error_ && connectionState_ == H_DISCONNECTING &&
               (events_ & EPOLLOUT)) {
        events_ = (EPOLLOUT | EPOLLET);
    } else {
        loop_->runInLoop(bind(&HttpMessage::handleClose, shared_from_this()));
    }
}

URIState HttpMessage::parseURI() {
    string &str = inBuffer_;
    size_t pos = str.find('\r');
    if (pos < 0) return PARSE_URI_ERROR;
    string request_line = str.substr(0, pos);
    if (str.size() > pos + 2) str = str.substr(pos + 2);
    else str.clear();
    int posGet = request_line.find("GET");
    int posPost = request_line.find("POST");
    int posHead = request_line.find("HEAD");

    if (posGet >= 0)method_ = METHOD_GET;
    else if (posPost >= 0)method_ = METHOD_POST;
    else if (posHead >= 0)method_ = METHOD_HEAD;
    else return PARSE_URI_ERROR;

    // filename
    pos = request_line.find('/');
    if (pos < 0) {
        fileName_ = "index.html";
        version_ = HTTP_11;
        return PARSE_URI_SUCCESS;
    } else {
        size_t pos1 = request_line.find(' ', pos);
        if (pos1 < 0) return PARSE_URI_ERROR;
        else {
            if (pos1 - pos > 1) {
                fileName_ = request_line.substr(pos + 1, pos1 - pos - 1);
                size_t pos2 = fileName_.find('?');
                if (pos2 >= 0) fileName_ = fileName_.substr(0, pos2);
            } else fileName_ = "index.html";
        }
        pos = pos1;
    }
    // HTTP 版本号
    pos = request_line.find('/', pos);
    if (pos < 0) return PARSE_URI_ERROR;
    else {
        if (request_line.size() - pos <= 3) return PARSE_URI_ERROR;
        else {
            string ver = request_line.substr(pos + 1, 3);
            if (ver == "1.0") version_ = HTTP_10;
            else if (ver == "1.1") version_ = HTTP_11;
            else return PARSE_URI_ERROR;
        }
    }
    return PARSE_URI_SUCCESS;
}

HeaderState HttpMessage::parseHeaders() {
    string &str = inBuffer_;
    while (1) {
        auto pos = str.find_first_of("\r\n");
        if (pos == std::string::npos) return PARSE_HEADER_ERROR;
        if (pos == 0) return PARSE_HEADER_SUCCESS;
        int flag = 0;
        string temp1, temp2;
        for (int i = 0; i < pos; i++) {
            if (str[i] == ' ') continue;
            if (str[i] != ':' && !flag) temp1 += str[i];
            else if (str[i] == ':') flag = 1;
            else if (str[i] != '\r' && flag) temp2 += str[i];
            else break;
        }
        headers_[temp1] = temp2;
        str = str.substr(pos + 2);
    }
}

AnalysisState HttpMessage::analysisRequest() {
    if (method_ == METHOD_POST) {
        std::string header;
        header += std::string("HTTP/1.1 200 OK\r\n");
        if (headers_.find("Connection") != headers_.end() &&
            headers_["Connection"] == "keep-alive") {
            keepAlive_ = true;
            header += std::string("Connection: keep-alive\r\n") + "Keep-Alive:timeout=" +
                      std::to_string(DEFAULT_KEEP_ALIVE_TIME) + "\r\n";
        }
        int length = std::stoi(headers_["Content-Length"]);
        header += std::string("Content-Length: ") + std::to_string(length) + "\r\n\r\n";
        inBuffer_ = inBuffer_.substr(2);
        outBuffer_ += header + inBuffer_;
        inBuffer_.clear();
        return ANALYSIS_SUCCESS;
    } else if (method_ == METHOD_GET || method_ == METHOD_HEAD) {
        string header;
        header += "HTTP/1.1 200 OK\r\n";
        if (headers_.find("Connection") != headers_.end() &&
            (headers_["Connection"] == "Keep-Alive" ||
             headers_["Connection"] == "keep-alive")) {
            keepAlive_ = true;
            header += string("Connection: Keep-Alive\r\n") + "Keep-Alive: timeout=" +
                      to_string(DEFAULT_KEEP_ALIVE_TIME) + "\r\n";
        }
        int dot_pos = fileName_.find('.');
        string filetype;
        if (dot_pos < 0) filetype = getType("default");
        else filetype = getType(fileName_.substr(dot_pos));
        struct stat sbuf;
        if (stat(fileName_.c_str(), &sbuf) < 0) {
            header.clear();
            handleError(fd_, 404, "Not Found!");
            return ANALYSIS_ERROR;
        }
        header += "Content-Type: " + filetype + "\r\n";
        header += "Content-Length: " + to_string(sbuf.st_size) + "\r\n";
        header += "HttpServer: PY's Web HttpServer\r\n";
        // 头部结束
        header += "\r\n";
        outBuffer_ += header;
        if (method_ == METHOD_HEAD) return ANALYSIS_SUCCESS;
        int src_fd = open(fileName_.c_str(), O_RDONLY, 0);
        if (src_fd < 0) {
            outBuffer_.clear();
            handleError(fd_, 404, "Not Found!");
            return ANALYSIS_ERROR;
        }
        void *mmapRet = mmap(NULL, sbuf.st_size, PROT_READ, MAP_PRIVATE, src_fd, 0);
        close(src_fd);
        if (mmapRet == (void *) -1) {
            munmap(mmapRet, sbuf.st_size);
            outBuffer_.clear();
            handleError(fd_, 404, "Not Found!");
            return ANALYSIS_ERROR;
        }
        char *src_addr = static_cast<char *>(mmapRet);
        outBuffer_ += string(src_addr, src_addr + sbuf.st_size);;
        munmap(mmapRet, sbuf.st_size);
        return ANALYSIS_SUCCESS;
    }
    return ANALYSIS_ERROR;
}

void HttpMessage::handleError(int fd, int err_num, string short_msg) {
    short_msg = " " + short_msg;
    char send_buff[4096];
    string body_buff, header_buff;
    body_buff += "<html><title>哎~出错了</title>";
    body_buff += "<body bgcolor=\"ffffff\">";
    body_buff += to_string(err_num) + short_msg;
    body_buff += "<hr><em> PY's Web HttpServer</em>\n</body></html>";
    header_buff += "HTTP/1.1 " + to_string(err_num) + short_msg + "\r\n";
    header_buff += "Content-Type: text/html\r\n";
    header_buff += "Connection: Close\r\n";
    header_buff += "Content-Length: " + to_string(body_buff.size()) + "\r\n";
    header_buff += "HttpServer: PY's Web HttpServer\r\n";;
    header_buff += "\r\n";
    // 错误处理不考虑writen不完的情况
    sprintf(send_buff, "%s", header_buff.c_str());
    writen(fd, send_buff, strlen(send_buff));
    sprintf(send_buff, "%s", body_buff.c_str());
    writen(fd, send_buff, strlen(send_buff));
}

void HttpMessage::handleClose() {
    connectionState_ = H_DISCONNECTED;
    shared_ptr<HttpMessage> guard(shared_from_this());
    loop_->removeFromPoller(channel_);
}

void HttpMessage::newEvent() {
    channel_->setEvents(DEFAULT_EVENT);
    loop_->addToPoller(channel_, DEFAULT_EXPIRED_TIME);
}
