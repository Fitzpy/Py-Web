//
// Created by py on 2020/5/4.
//

#include "Epoll.h"
#include <cassert>
#include <sys/epoll.h>
#include <queue>
#include "Util.h"
#include "Logging.h"

const int EVENTSNUM = 4096;
const int EPOLLWAIT_TIME = 10000;

typedef std::shared_ptr<Channel> SharePtrChannel;

Epoll::Epoll() : epollFd_(epoll_create(EPOLL_CLOEXEC)), events_(EVENTSNUM) {
    assert(epollFd_ > 0);
}

Epoll::~Epoll() {}

void Epoll::epoll_add(SharePtrChannel request, int timeout) {
    int fd = request->getFd();
    if (timeout > 0) {
        add_timer(request, timeout);
        fd2Http_[fd] = request->getHolder();
    }
    struct epoll_event event;
    event.data.fd = fd;
    event.events = request->getEvents();
    request->EqualAndUpdateLastEvents();
    fd2chan_[fd] = request;
    if (epoll_ctl(epollFd_, EPOLL_CTL_ADD, fd, &event) < 0) {
        perror("epoll_add error");
        fd2chan_[fd].reset();
    }
}

void Epoll::epoll_mod(SharePtrChannel request, int timeout) {
    if (timeout > 0) add_timer(request, timeout);
    int fd = request->getFd();
    if (!request->EqualAndUpdateLastEvents()) {
        struct epoll_event event;
        event.data.fd = fd;
        event.events = request->getEvents();
        if (epoll_ctl(epollFd_, EPOLL_CTL_MOD, fd, &event) < 0) {
            perror("epoll_moderror");
            fd2chan_[fd].reset();
        }
    }
}

void Epoll::epoll_del(SharePtrChannel request) {
    int fd = request->getFd();
    struct epoll_event event;
    event.data.fd = fd;
    event.events = request->getLastEvents();
    if (epoll_ctl(epollFd_, EPOLL_CTL_DEL, fd, &event) < 0) {
        perror("epoll_del error");
    }
    fd2chan_[fd].reset();
    fd2Http_[fd].reset();
}

std::vector<SharePtrChannel> Epoll::poll() {
    while (true) {
        int event_count = epoll_wait(epollFd_, &*events_.begin(), events_.size(), EPOLLWAIT_TIME);
        if (event_count < 0) perror("epoll_wait error");
        std::vector<SharePtrChannel> req_data = getEventsRequest(event_count);
        if (req_data.size() > 0) return req_data;
    }
}

void Epoll::handleExpired() { timerManager_.handleExpiredEvent(); }

std::vector<SharePtrChannel> Epoll::getEventsRequest(int events_num) {
    std::vector<SharePtrChannel> req_data;
    for (int i = 0; i < events_num; ++i) {
        int fd = events_[i].data.fd;
        SharePtrChannel cur_req = fd2chan_[fd];
        if (cur_req) {
            cur_req->setRevents(events_[i].events);
            cur_req->setEvents(0);
            req_data.push_back(cur_req);
        } else {
            LOG << "SP cur_req is invalid";
        }
    }
    return req_data;
}

void Epoll::add_timer(std::shared_ptr<Channel> request, int timeout) {
    std::shared_ptr<HttpMessage> t = request->getHolder();
    if (t) timerManager_.addTimer(t, timeout);
    else
        LOG << "timer add fail";
}

