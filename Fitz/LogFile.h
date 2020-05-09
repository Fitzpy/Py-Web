//
// Created by py on 2020/5/2.
//

#ifndef FITZ_LOGFILE_H
#define FITZ_LOGFILE_H

#include <memory>
#include <string>
#include "FileUtil.h"
#include "MutexLock.h"
#include "noncopyable.h"

class LogFile : noncopyable {
public:
    // 每被append flushEveryN次，flush一下，会往文件写，只不过，文件也是带缓冲区的
    LogFile(std::string basename, int flushEveryN = 1024);

    ~LogFile();

    void append(const char *logline, int len);

    void flush();


private:
    void append_unlocked(const char *logline, int len);
    const std::string basename_;
    const int flushEveryN_;
    int count_;
    std::unique_ptr<MutexLock> mutex_;
    std::unique_ptr<AppendFile> file_;

};

#endif //FITZ_LOGFILE_H
