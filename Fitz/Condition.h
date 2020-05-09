//
// Created by py on 2020/5/2.
//

#ifndef FITZ_CONDITION_H
#define FITZ_CONDITION_H
#pragma once
#include <cerrno>
#include <pthread.h>
#include <ctime>
#include <cstdint>
#include "MutexLock.h"
#include "noncopyable.h"
class Condition:noncopyable{
public:
    explicit Condition(MutexLock &_mutex):mutex(_mutex){
        pthread_cond_init(&cond,NULL);
    }
    ~Condition(){
        pthread_cond_destroy(&cond);
    }
    void wait(){
        pthread_cond_wait(&cond,mutex.get());
    }
    void notify(){
        pthread_cond_signal(&cond);
    }
    void notifyAll(){
        pthread_cond_broadcast(&cond);
    }
    bool waitForSeconds(int seconds){
        struct timespec abstime;
        clock_gettime(CLOCK_REALTIME,&abstime);//获得时间，从1970-1-1 0:0:0开始计时
        abstime.tv_sec+= static_cast<time_t>(seconds);//希望等待的时间，也就是到
        return ETIMEDOUT == pthread_cond_timedwait(&cond,mutex.get(),&abstime);
        //在等待过程中是可以触发条件的。
    }
private:
    MutexLock & mutex;
    pthread_cond_t cond;
};
#endif //FITZ_CONDITION_H
