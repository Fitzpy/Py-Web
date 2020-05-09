//
// Created by py on 2020/5/2.
//

#include "LogFile.h"

#include <utility>
#include "FileUtil.h"

using namespace std;

LogFile::LogFile(std::string basename, int flushEveryN)
        : basename_(std::move(basename)),
          flushEveryN_(flushEveryN),
          count_(0),
          mutex_(new MutexLock) {
    file_.reset(new AppendFile(basename_));
}

LogFile::~LogFile() {}

void LogFile::append(const char *logline, int len) {
    MutexLockGuard lock(*mutex_);
    append_unlocked(logline, len);
}

void LogFile::flush() {
    MutexLockGuard lock(*mutex_);
    file_->flush();
}

void LogFile::append_unlocked(const char *logline, int len) {
    file_->append(logline, len);
    ++count_;
    if (count_ >= flushEveryN_) {
        count_ = 0;
        file_->flush();
    }
}