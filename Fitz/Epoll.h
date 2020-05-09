//
// Created by py on 2020/5/4.
//

#ifndef FITZ_EPOLL_H
#define FITZ_EPOLL_H

#include <sys/epoll.h>
#include <memory>
#include <unordered_map>
#include <vector>
#include "Channel.h"
#include "HttpMessage.h"
#include "Timer.h"

class Epoll {
public:
    Epoll();

    ~Epoll();

    void epoll_add(SharePtrChannel request, int timeout);

    void epoll_mod(SharePtrChannel request, int timeout);

    void epoll_del(SharePtrChannel request);

    std::vector<std::shared_ptr<Channel>> poll();

    std::vector<std::shared_ptr<Channel>> getEventsRequest(int events_num);

    void add_timer(std::shared_ptr<Channel> request, int timeout);

    int getEpollFd() {
        return epollFd_;
    }

    void handleExpired();

private:
    static const int MAXFDS = 100000;
    int epollFd_;
    std::vector<epoll_event> events_;
    std::shared_ptr<Channel> fd2chan_[MAXFDS];
    std::shared_ptr<HttpMessage> fd2Http_[MAXFDS];
    TimerManager timerManager_;
};

#endif //FITZ_EPOLL_H
