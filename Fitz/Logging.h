//
// Created by py on 2020/5/2.
//

#ifndef FITZ_LOGGING_H
#define FITZ_LOGGING_H
#pragma once

#include <pthread.h>
#include <cstdio>
#include <string>
#include <utility>
#include "LogStream.h"

class AsyncLogging;

class Logger {
public:
    Logger(const char *fileName, int line);

    ~Logger();

    LogStream &stream() {
        return imp1_.stream_;
    }

    static void setLogFileName(std::string FileName) {
        logFileName_ = std::move(FileName);
    }

    static std::string getLogFileName() {
        return logFileName_;
    }

private:
    class Imp1 {
    public:
        Imp1(const char *fileName, int line);

        void formatTime();

        LogStream stream_;
        int line_;
        std::string basename_;
    };

    Imp1 imp1_;
    static std::string logFileName_;
};
#define LOG Logger(__FILE__,__LINE__).stream()
#endif //FITZ_LOGGING_H
