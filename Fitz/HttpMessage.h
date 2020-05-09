//
// Created by py on 2020/5/2.
//

#ifndef FITZ_HTTPMESSAGE_H
#define FITZ_HTTPMESSAGE_H
#pragma once

#include <sys/epoll.h>
#include <unistd.h>
#include <functional>
#include <map>
#include <memory>
#include <string>
#include <unordered_map>
#include "Timer.h"

class EventLoop;

class TimerNode;

class Channel;

enum ProcessState {
    STATE_PARSE_URI = 1,
    STATE_PARSE_HEADERS,
    STATE_RECV_BODY,
    STATE_ANALYSIS,
    STATE_FINISH
};
enum URIState {
    PARSE_URI_AGAIN = 1,
    PARSE_URI_ERROR,
    PARSE_URI_SUCCESS,
};

enum HeaderState {
    PARSE_HEADER_SUCCESS = 1,
    PARSE_HEADER_ERROR
};

enum AnalysisState {
    ANALYSIS_SUCCESS = 1, ANALYSIS_ERROR
};

enum ConnectionState {
    H_CONNECTED = 0, H_DISCONNECTING, H_DISCONNECTED
};

enum HttpMethod {
    METHOD_POST = 1, METHOD_GET, METHOD_HEAD
};

enum HttpVersion {
    HTTP_10 = 1, HTTP_11
};

class HttpMessage : public std::enable_shared_from_this<HttpMessage> {
public:
    HttpMessage(EventLoop *loop, int connfd);

    ~HttpMessage() {
        close(fd_);
    }

    void reset();

    void resetTimer();

    void linkTimer(std::shared_ptr<TimerNode> mtimer) {
        timer_ = mtimer;
    }

    std::shared_ptr<Channel> getChannel() {
        return channel_;
    }

    EventLoop *getLoop() {
        return loop_;
    }

    void handleClose();

    void newEvent();

private:
    EventLoop *loop_;
    std::shared_ptr<Channel> channel_;
    int fd_;
    std::string inBuffer_;
    std::string outBuffer_;
    bool error_;
    ConnectionState connectionState_;
    HttpMethod method_;
    HttpVersion version_;
    std::string fileName_;
    std::string path_;
    ProcessState state_;
    bool keepAlive_;
    std::map<std::string, std::string> headers_;
    std::weak_ptr<TimerNode> timer_;
    static std::unordered_map<std::string, std::string> type;

    static std::string getType(const std::string &suffix);

    void handleRead();

    void handleWrite();

    void handleConn();

    static void handleError(int fd, int err_num, std::string short_msg);

    URIState parseURI();

    HeaderState parseHeaders();

    AnalysisState analysisRequest();
};

#endif //FITZ_HTTPMESSAGE_H
