//
// Created by py on 2020/5/4.
//

#ifndef FITZ_HTTPSERVER_H
#define FITZ_HTTPSERVER_H
#pragma once

#include <memory>
#include "Channel.h"
#include "EventLoop.h"
#include "EventLoopThreadPool.h"

class HttpServer {
public:
    HttpServer(EventLoop *loop, int threadNum, int port);

    ~HttpServer(){};

    EventLoop *getLoop() const {
        return loop_;
    }

    void start();

    void handNewConn();

    void handThisConn() {
        loop_->updatePoller(acceptChannel_);
    }

private:
    EventLoop *loop_;
    int threadNum_;
    std::unique_ptr<EventLoopThreadPool> eventLoopThreadPool_;
    bool started_;
    std::shared_ptr<Channel> acceptChannel_;
    int port_;
    int listenFd_;
    static const int MaxFds = 100000;
};

#endif //FITZ_HTTPSERVER_H
