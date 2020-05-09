//
// Created by py on 2020/5/4.
//
#include "HttpServer.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "Util.h"
#include "Logging.h"

HttpServer::HttpServer(EventLoop *loop, int threadNum, int port)
        : loop_(loop),
          threadNum_(threadNum),
          eventLoopThreadPool_(new EventLoopThreadPool(loop_, threadNum)),
          started_(false),
          acceptChannel_(new Channel(loop_)),
          port_(port),
          listenFd_(socket_bind_listen(port_)) {
    acceptChannel_->setFd(listenFd_);
    handle_for_sigpipe();
    if (setSocketNonBlocking(listenFd_) < 0) {
        perror("set socket non block failed");
        abort();
    }
}

void HttpServer::start() {
    eventLoopThreadPool_->start();
    acceptChannel_->setEvents(EPOLLIN | EPOLLET);
    acceptChannel_->setReadHandler([this] { handNewConn(); });
    acceptChannel_->setWriteHandler([this] { handThisConn(); });
    loop_->addToPoller(acceptChannel_, 0);
    started_ = true;
}

void HttpServer::handNewConn() {
    struct sockaddr_in client_addr;
    memset(&client_addr, 0, sizeof(struct sockaddr_in));
    socklen_t client_addr_len = sizeof(client_addr);
    int accept_fd = 0;
    while ((accept_fd = accept(listenFd_, (struct sockaddr *) &client_addr, &client_addr_len)) > 0) {
        EventLoop *loop = eventLoopThreadPool_->getNextLoop();
        LOG << "New connection from " << inet_ntoa(client_addr.sin_addr) << ":"
            << ntohs(client_addr.sin_port);
        if (accept_fd >= MaxFds) {
            close(accept_fd);
            continue;
        }
        if (setSocketNonBlocking(accept_fd) < 0) {
            LOG << "Set non block failed!";
            return;
        }
        setSocketNodelay(accept_fd);
        std::shared_ptr<HttpMessage> req_info(new HttpMessage(loop, accept_fd));
        req_info->getChannel()->setHolder(req_info);
        loop->queueInLoop([req_info] { req_info->newEvent(); });
    }
    acceptChannel_->setEvents(EPOLLIN | EPOLLET);
}