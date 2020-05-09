//
// Created by py on 2020/5/4.
//

#ifndef FITZ_CHANNEL_H
#define FITZ_CHANNEL_H

#include <sys/epoll.h>
#include <functional>
#include <memory>
#include <string>
#include <unordered_map>
#include "Timer.h"

class EventLoop;

class HttpMessage;

class Channel {
public:
    typedef std::function<void()> CallBack;

    Channel(EventLoop *loop);

    Channel(EventLoop *loop, int fd);

    ~Channel();

    int getFd();

    void setFd(int fd);

    void setHolder(std::shared_ptr<HttpMessage> holder) {
        holder_ = holder;
    }

    std::shared_ptr<HttpMessage> getHolder() {
        std::shared_ptr<HttpMessage> ret(holder_.lock());
        return ret;
    }

    void setReadHandler(CallBack &&readHandler) {
        readHandler_ = readHandler;
    }

    void setWriteHandler(CallBack &&writeHandler) {
        writeHandler_ = writeHandler;
    }

    void setErrorHandler(CallBack &&errorHandler) {
        errorHandler_ = errorHandler;
    }

    void setConHandler(CallBack &&connHandler) {
        connHandle_ = connHandler;
    }

    void handleEvents() {
        events_ = 0;
        if ((revents_ & EPOLLHUP) && !(revents_ & EPOLLIN)) {
            events_ = 0;
            return;
        }
        if (revents_ & EPOLLERR) {
            if (errorHandler_) errorHandler_();
            events_ = 0;
            return;
        }
        if (revents_ & (EPOLLIN | EPOLLPRI | EPOLLRDHUP)) {
            handleRead();
        }
        if (events_ & EPOLLOUT) {
            handleWrite();
        }
        handleConn();
    }

    void handleRead();

    void handleWrite();

    void handleError(int fd, int err_num, std::string short_msg);

    void handleConn();

    void setRevents(int ev) {
        revents_ = ev;
    }

    void setEvents(int ev) {
        events_ = ev;
    }

    unsigned int &getEvents() {
        return events_;
    }

    bool EqualAndUpdateLastEvents() {
        bool ret = (lastEvents_ == events_);
        lastEvents_ = events_;
        return ret;
    }

    int getLastEvents() const {
        return lastEvents_;
    }

private:
    int fd_;
    EventLoop *loop_;
    unsigned int events_;
    unsigned int revents_;
    unsigned int lastEvents_;
    std::weak_ptr<HttpMessage> holder_;
    CallBack readHandler_;
    CallBack writeHandler_;
    CallBack errorHandler_;
    CallBack connHandle_;
};

typedef std::shared_ptr<Channel> SharePtrChannel;
#endif //FITZ_CHANNEL_H
