//
// Created by py on 2020/4/30.
//

#ifndef FITZ_NONCOPYABLE_H
#define FITZ_NONCOPYABLE_H

class noncopyable {
public:
    noncopyable() {}

    ~noncopyable() {}

private:
    noncopyable(const noncopyable &);

    const noncopyable &operator=(const noncopyable &);
};

#endif //FITZ_NONCOPYABLE_H


