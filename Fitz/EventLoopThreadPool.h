//
// Created by py on 2020/5/4.
//

#ifndef FITZ_EVENTLOOPTHREADPOOL_H
#define FITZ_EVENTLOOPTHREADPOOL_H
#pragma once

#include <memory>
#include <vector>
#include "EventLoopThread.h"
#include "Logging.h"
#include "noncopyable.h"

class EventLoopThreadPool : noncopyable {
public:
    EventLoopThreadPool(EventLoop *baseLoop, int numThreads);

    ~EventLoopThreadPool() {
        LOG << "~EventLoopThreadPool()";
    }

    void start();

    EventLoop *getNextLoop();

private:
    EventLoop *baseLoop_;
    bool started_;
    int numTHreads_;
    int next_;
    std::vector<std::shared_ptr<EventLoopThread>> threads_;
    std::vector<EventLoop*> loops_;
};

#endif //FITZ_EVENTLOOPTHREADPOOL_H
