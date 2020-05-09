//
// Created by py on 2020/5/5.
//

#include "EventLoop.h"
#include <sys/epoll.h>
#include <sys/eventfd.h>
#include "Util.h"
#include "Logging.h"

__thread EventLoop *t_loopInThisThread = nullptr;

int createEventfd() {
    int evtfd = eventfd(0, EFD_NONBLOCK | EFD_CLOEXEC);
    if (evtfd < 0) {
        LOG << "Failed in create eventfd";
        abort();
    }
    return evtfd;
}

EventLoop::EventLoop()
        : looping_(false),
          poller_(new Epoll()),
          wakeupFd_(createEventfd()),
          quit_(false),
          eventHandling_(false),
          callingPendingFunctors(false),
          threadId_(CurrentThread::tid()),
          pwakeupChannel_(new Channel(this, wakeupFd_)) {
    if (t_loopInThisThread) {

    } else {
        t_loopInThisThread = this;
    }
    pwakeupChannel_->setEvents(EPOLLIN | EPOLLET);
    pwakeupChannel_->setReadHandler([this] { handleRead(); });
    pwakeupChannel_->setConHandler([this] { handleConn(); });
    poller_->epoll_add(pwakeupChannel_, 0);
}

EventLoop::~EventLoop() {
    close(wakeupFd_);
    t_loopInThisThread = nullptr;
}

void EventLoop::handleConn() {
    updatePoller(pwakeupChannel_, 0);
}

void EventLoop::wakeup() const {
    uint64_t one = 1;
    ssize_t n = writen(wakeupFd_, (char *) (&one), sizeof(one));
    if (n != sizeof(one)) {
        LOG << "EventLoop::wakeup() writes " << n << " bytes instead of 8";
    }
}

void EventLoop::handleRead() {
    uint64_t one = 1;
    ssize_t n = readn(wakeupFd_, &one, sizeof(one));
    if (n != sizeof(one)) {
        LOG << "EventLoop::handleRead() reads " << n << " bytes instead of 8";
    }
    pwakeupChannel_->setEvents(EPOLLIN | EPOLLET);
}

void EventLoop::runInLoop(Functor &&cb) {
    if (isInLoopThread()) cb();
    else queueInLoop(std::move(cb));
}

void EventLoop::queueInLoop(Functor &&cb) {
    {
        MutexLockGuard lock(mutex_);
        pendingFunctors_.emplace_back(std::move(cb));
    }
    if (!isInLoopThread() || callingPendingFunctors) wakeup();
}

void EventLoop::loop() {
    assert(!looping_);
    assert(isInLoopThread());
    looping_ = true;
    quit_ = false;
    std::vector<SharePtrChannel> ret;
    while (!quit_) {
        ret.clear();
        ret = poller_->poll();
        eventHandling_ = true;
        for (auto &it :ret) it->handleEvents();
        eventHandling_ = false;
        doPendingFunctors();
        poller_->handleExpired();
    }
    looping_ = false;
}

void EventLoop::doPendingFunctors() {
    std::vector<Functor> functors;
    callingPendingFunctors = true;
    {
        MutexLockGuard lock(mutex_);
        functors.swap(pendingFunctors_);
    }
    for (auto &functor : functors) functor();
    callingPendingFunctors = false;
}

void EventLoop::quit() {
    quit_ = true;
    if (isInLoopThread()) wakeup();
}





