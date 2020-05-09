//
// Created by py on 2020/5/2.
//

#include "CountDownLatch.h"

CountDownLatch::CountDownLatch(int count)
        : mutex_(), condition_(mutex_), count_(count) {
}

void CountDownLatch::wait() {
    MutexLockGuard lock(mutex_);
    while (count_ > 0) condition_.wait();
}

void CountDownLatch::CountDown() {
    MutexLockGuard lock(mutex_);
    --count_;
    if (!count_) condition_.notifyAll();
}