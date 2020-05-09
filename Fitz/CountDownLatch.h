//
// Created by py on 2020/5/2.
//

#ifndef FITZ_COUNTDOWNLATCH_H
#define FITZ_COUNTDOWNLATCH_H

#pragma once
#include "Condition.h"
#include "MutexLock.h"
#include "noncopyable.h"
class CountDownLatch:noncopyable{
public:
    explicit CountDownLatch(int count);
    void wait();
    void CountDown();
private:
    //mutable关键词表示mutex_量是可以变的，即便在const函数中
    mutable MutexLock  mutex_;
    Condition condition_;
    int count_;
};
#endif //FITZ_COUNTDOWNLATCH_H