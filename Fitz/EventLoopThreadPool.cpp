//
// Created by py on 2020/5/5.
//

#include "EventLoopThreadPool.h"

EventLoopThreadPool::EventLoopThreadPool(EventLoop *baseLoop, int numThreads)
        : baseLoop_(baseLoop), started_(false), numTHreads_(numThreads), next_(0) {
    if (numTHreads_ <= 0) {
        LOG << "numThreads_ <= 0";
        abort();
    }
}

void EventLoopThreadPool::start() {
    baseLoop_->assertInLoopThread();
    started_ = true;
    for (int i = 0; i < numTHreads_; i++) {
        std::shared_ptr<EventLoopThread> t(new EventLoopThread());
        threads_.push_back(t);
        loops_.push_back(t->startLoop());
    }
}
EventLoop * EventLoopThreadPool::getNextLoop() {
    baseLoop_->assertInLoopThread();
    assert(started_);
    EventLoop * loop = baseLoop_;
    if (!loops_.empty()) {
        loop = loops_[next_];
        next_ = (next_+1)%numTHreads_;
    }
    return  loop;
}
