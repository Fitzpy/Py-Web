//
// Created by py on 2020/5/2.
//

#ifndef FITZ_MUTEXLOCK_H
#define FITZ_MUTEXLOCK_H

#pragma once

#include <pthread.h>
#include <cstdio>
#include "noncopyable.h"

class MutexLock : noncopyable {
public:
    MutexLock() {
        pthread_mutex_init(&mutex, NULL);
    }

    ~MutexLock() {
        pthread_mutex_destroy(&mutex);
    }

    void lock() {
        pthread_mutex_lock(&mutex);
    }

    void unlock() {
        pthread_mutex_unlock(&mutex);
    }

    pthread_mutex_t *get() {
        return &mutex;
    }

private:
    pthread_mutex_t mutex;

    friend class Condition;
};
/*上锁和解锁封装在一个类的构造和析构函数中，这样保证上锁和解锁在一个同一个函数同一个代码块中，
 *只要在一个代码块中定义这个类变量,然后在这个代码块中就自动上锁，然后代码块结束，就自动释放锁*/
class MutexLockGuard : noncopyable {
public:
    explicit MutexLockGuard(MutexLock &_mutex) : mutex(_mutex) {
        mutex.lock();
    }

    ~MutexLockGuard() {
        mutex.unlock();
    }

private:
    MutexLock &mutex;
};

#endif //FITZ_MUTEXLOCK_H
