//
// Created by py on 2020/5/2.
//

#ifndef FITZ_TIMER_H
#define FITZ_TIMER_H
#pragma once

#include <unistd.h>
#include <deque>
#include <memory>
#include <queue>
#include "HttpMessage.h"
#include "MutexLock.h"
#include "noncopyable.h"

class HttpMessage;

class TimerNode {
public:
    TimerNode(std::shared_ptr<HttpMessage> request, int timeout);

    ~TimerNode();

    TimerNode(TimerNode &TN);

    void updata(int timeout);

    bool isValid();

    void clearReq();

    void setDeleted() {
        deleted_ = true;
    }

    bool isDeleted() const {
        return deleted_;
    }

    ssize_t expiredTime() const {
        return expiredTime_;
    }

private:
    bool deleted_;
    size_t expiredTime_;
    std::shared_ptr<HttpMessage> SharePtrHttpData_;
};

struct TimerCmp {
    bool operator()(std::shared_ptr<TimerNode> &a, std::shared_ptr<TimerNode> &b) {
        return a->expiredTime() > b->expiredTime();
    }
};

class TimerManager {
public:
    TimerManager();

    ~TimerManager();

    void addTimer(std::shared_ptr<HttpMessage> SharePtrHttpData, int timeout);

    void handleExpiredEvent();

private:
    typedef std::shared_ptr<TimerNode> SharePtrTimerNode;
    std::priority_queue<SharePtrTimerNode, std::deque<SharePtrTimerNode>, TimerCmp> timerQueue;
};

#endif //FITZ_TIMER_H
