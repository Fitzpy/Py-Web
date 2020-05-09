//
// Created by py on 2020/5/4.
//

#ifndef FITZ_EVENTLOOPTHREAD_H
#define FITZ_EVENTLOOPTHREAD_H


#include "EventLoop.h"
#include "Condition.h"
#include "MutexLock.h"
#include "Thread.h"
#include "noncopyable.h"

class EventLoopThread : noncopyable {
public:
    EventLoopThread();

    ~EventLoopThread();

    EventLoop *startLoop();

private:
    void threadFunc();

    EventLoop *loop_;
    bool exiting_;
    Thread thread_;
    MutexLock mutex_;
    Condition cond_;
};

#endif //FITZ_EVENTLOOPTHREAD_H
