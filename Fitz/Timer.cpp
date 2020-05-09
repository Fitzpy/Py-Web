//
// Created by py on 2020/5/4.
//

#include "Timer.h"
#include <sys/time.h>
#include <unistd.h>
#include <queue>

TimerNode::TimerNode(std::shared_ptr<HttpMessage> request, int timeout)
        : deleted_(false), SharePtrHttpData_(request) {
    struct timeval now;
    gettimeofday(&now, NULL);
    expiredTime_ = now.tv_sec * 1000 + (now.tv_usec / 1000) + timeout;
}
TimerNode::~TimerNode() {
    if (SharePtrHttpData_) SharePtrHttpData_->handleClose();
}

TimerNode::TimerNode(TimerNode &TN)
        : SharePtrHttpData_(TN.SharePtrHttpData_), expiredTime_(0) {
}

void TimerNode::updata(int timeout) {
    struct timeval now;
    gettimeofday(&now, NULL);
    expiredTime_ = now.tv_sec * 1000 + (now.tv_usec / 1000) + timeout;
}

bool TimerNode::isValid() {
    struct timeval now;
    gettimeofday(&now, NULL);
    size_t temp = now.tv_sec * 1000 + now.tv_usec / 1000;
    if (temp < expiredTime_) return true;
    else {
        this->setDeleted();
        return false;
    }
}

void TimerNode::clearReq() {
    SharePtrHttpData_.reset();
    this->setDeleted();
}

TimerManager::TimerManager() {}

TimerManager::~TimerManager() {}

void TimerManager::addTimer(std::shared_ptr<HttpMessage> SharePtrHttpData, int timeout) {
    SharePtrTimerNode node(new TimerNode(SharePtrHttpData, timeout));
    timerQueue.push(node);
    SharePtrHttpData->linkTimer(node);
}

void TimerManager::handleExpiredEvent() {
    while (!timerQueue.empty()) {
        SharePtrTimerNode now = timerQueue.top();
        if (now->isDeleted()) timerQueue.pop();
        else if (!now->isValid()) timerQueue.pop();
        else break;
    }
}

