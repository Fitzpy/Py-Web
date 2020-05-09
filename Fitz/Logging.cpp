//
// Created by py on 2020/5/2.
//

#include "Logging.h"
#include "AsyncLogging.h"
#include <sys/time.h>

static pthread_once_t once_control = PTHREAD_ONCE_INIT;
static AsyncLogging *AsyncLogger_;

std::string Logger::logFileName_ = "./WebServer.log";

void once_init() {
    AsyncLogger_ = new AsyncLogging(Logger::getLogFileName());
    AsyncLogger_->start();
}

void output(const char *msg, int len) {
    pthread_once(&once_control, once_init);
    AsyncLogger_->append(msg, len);
}

Logger::Imp1::Imp1(const char *fileName, int line)
        : stream_(),
          line_(line),
          basename_(fileName) {
    formatTime();
}

void Logger::Imp1::formatTime() {
    struct timeval tv;
    time_t time;
    char str_t[26];
    gettimeofday(&tv, NULL);
    time = tv.tv_sec;
    struct tm *p_time = localtime(&time);
    strftime(str_t, 26, "%Y-%m-%d %H:%M:%S\n", p_time);
    stream_ << str_t;
}

Logger::Logger(const char *fileName, int line)
        : imp1_(fileName, line) {

}

Logger::~Logger() {
    imp1_.stream_ << " -- " << imp1_.basename_ << ":" << imp1_.line_ << "\n";
    const LogStream::Buffer &buf(stream().buffer());
    output(buf.data(), buf.length());
}
