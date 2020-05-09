//
// Created by py on 2020/5/2.
//

#ifndef FITZ_FILEUTIL_H
#define FITZ_FILEUTIL_H
#pragma once

#include <string>
#include "noncopyable.h"

class AppendFile : noncopyable {
public:
    explicit AppendFile(const std::string& filename);
    ~AppendFile();
    void append(const char * logline,size_t len);
    void flush();
private:
    size_t write(const char *logline, size_t len);

    FILE *fp_;
    char buffer_[64 * 1024]{};
};

#endif //FITZ_FILEUTIL_H
