//
// Created by py on 2020/5/2.
//

#include "Thread.h"
#include <cassert>
#include <linux/unistd.h>
#include <cstdio>
#include <sys/prctl.h>
#include <unistd.h>
#include <string>
#include <utility>
#include "CurrentThread.h"

using namespace std;
namespace CurrentThread {
    // __thread修饰的变量是线程局部存储的，就是每个线程有自己单独的一份变量。
    __thread int t_cachedTid = 0;
    __thread char t_tidString[32];
    __thread int t_tidStringLength = 6;
    __thread const char *t_threadName = "default";
}

pid_t getTid() {
    return static_cast<pid_t>(::syscall(SYS_gettid));
}

void CurrentThread::cacheTid() {
    if (t_cachedTid == 0) {
        t_cachedTid = getTid();
        t_tidStringLength =
                snprintf(t_tidString, sizeof t_tidString, "%5d ", t_cachedTid);
    }
}

struct ThreadData {
    typedef Thread::ThreadFunc ThreadFunc;
    ThreadFunc func_;
    string name_;
    pid_t *tid_;
    CountDownLatch *latch_;

    ThreadData(ThreadFunc func, string name, pid_t *tid, CountDownLatch *latch)
            : func_(std::move(func)), name_(std::move(name)), tid_(tid), latch_(latch) {
    }

    void runInThread() {
        *tid_ = CurrentThread::tid();
        tid_ = nullptr;
        latch_->CountDown();
        latch_ = nullptr;
        CurrentThread::t_threadName = name_.empty() ? "Thread" : name_.c_str();
        prctl(PR_SET_NAME, CurrentThread::t_threadName);
        func_();
        CurrentThread::t_threadName = "finished";
    }
};

void *startThread(void *obj) {
    auto *data = static_cast<ThreadData *>(obj);
    data->runInThread();
    delete data;
    return nullptr;
}

Thread::Thread(ThreadFunc func, std::string name)
        : started_(false), joined_(false), pthreadId_(0),
          tid_(0), func_(std::move(func)), name_(std::move(name)), latch_(1) {
    setDefaultName();
}

Thread::~Thread() {
    if (started_ && !joined_) pthread_detach(pthreadId_);
}

void Thread::setDefaultName() {
    if (name_.empty()) {
        char buf[32];
        snprintf(buf, sizeof buf, "Thread");
        name_ = buf;
    }
}

void Thread::start() {
    assert(!started_);
    started_ = true;
    auto *data = new ThreadData(func_, name_, &tid_, &latch_);
    if (pthread_create(&pthreadId_, nullptr, &startThread, data)) {
        started_ = false;
        delete data;
    } else {
        latch_.wait();
        assert(tid_ > 0);
    }
}

int Thread::join() {
    assert(started_);
    assert(!joined_);
    joined_ = true;
    return pthread_join(pthreadId_, nullptr);
}
