//
// Created by py on 2020/5/2.
//

#ifndef FITZ_ASYNCLOGGING_H
#define FITZ_ASYNCLOGGING_H
#pragma once

#include <functional>
#include <string>
#include <vector>
#include "CountDownLatch.h"
#include "LogStream.h"
#include "MutexLock.h"
#include "Thread.h"
#include "noncopyable.h"

/* AsyncLogging就是实现一步日志的类，其中有两个主要函数threadFunc和append，
 * append线程是由各种其他线程来执行的，就是把日志内容写到相应的缓存区中，
 * threadFunc函数则是由一个专门线程负责，就是把缓存区中的数据写入日志文件当中*/

class AsyncLogging : noncopyable {
public:
    AsyncLogging(const std::string& basename, int flushInterval = 2);

    ~AsyncLogging() {
        if (running_) stop();
    }

    void append(const char *logline, int len);

    void start() {
        running_ = true;
        thread_.start();
        latch_.wait();
    }

    void stop() {
        running_ = false;
        cond_.notify();
        thread_.join();
    }

private:
    void threadFunc();

    typedef FixedBuffer<kLargeBuffer> Buffer;
    typedef std::vector<std::shared_ptr<Buffer>> BufferVector;
    typedef std::shared_ptr<Buffer> BufferPtr;
    const int flushInterval_; //超时时间，在flushInterval_秒内，缓冲区没有写满，仍将缓冲区的数据写到文件中
    bool running_;
    std::string basename_;
    Thread thread_;
    MutexLock mutex_;
    Condition cond_;
    BufferPtr currentBuffer_;// 当前的缓冲区
    BufferPtr nextBuffer_;// 预备的缓冲区，muduo异步日志中采用了双缓存技术
    BufferVector buffers_;// 缓冲区队列，每写完一个缓冲区，就把这个缓冲区挂到队列中，这些缓存都是等待待写入的文件
    CountDownLatch latch_;// 计数器
};

#endif //FITZ_ASYNCLOGGING_H
