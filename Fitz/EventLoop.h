//
// Created by py on 2020/5/4.
//

#ifndef FITZ_EVENTLOOP_H
#define FITZ_EVENTLOOP_H

#include <iostream>
#include <memory>
#include <vector>
#include <functional>
#include "Channel.h"
#include "Epoll.h"
#include "Util.h"
#include "CurrentThread.h"
#include "Logging.h"
#include "Thread.h"

class EventLoop {
public:
    typedef std::function<void()> Functor;

    EventLoop();

    ~EventLoop();

    void loop();

    void quit();

    void runInLoop(Functor &&cb);

    void queueInLoop(Functor &&cb);

    bool isInLoopThread() const {
        return threadId_ == CurrentThread::tid(); }

    void assertInLoopThread() {
        assert(isInLoopThread());
    }

    void removeFromPoller(std::shared_ptr<Channel> channel) {
        poller_->epoll_del(channel);
    }

    void updatePoller(std::shared_ptr<Channel> channel, int timeout = 0) {
        poller_->epoll_mod(channel, timeout);
    }

    void addToPoller(std::shared_ptr<Channel> channel, int timeout = 0) {
        poller_->epoll_add(channel, timeout);
    }

private:
    bool looping_;
    std::shared_ptr<Epoll> poller_;
    int wakeupFd_;
    bool quit_;
    bool eventHandling_;
    mutable MutexLock mutex_;
    std::vector<Functor> pendingFunctors_;
    bool callingPendingFunctors;
    const pid_t threadId_;
    std::shared_ptr<Channel> pwakeupChannel_;

    void wakeup() const;

    void handleRead();

    void doPendingFunctors();

    void handleConn();
};

#endif //FITZ_EVENTLOOP_H
