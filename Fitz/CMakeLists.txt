cmake_minimum_required(VERSION 3.16)
project(Fitz)

set(CMAKE_CXX_STANDARD 14)

add_executable(Fitz main.cpp
        noncopyable.h
        CountDownLatch.h
        Condition.h
        MutexLock.h
        CountDownLatch.cpp
        Thread.h
        Thread.cpp
        CurrentThread.h
        FileUtil.h
        FileUtil.cpp
        LogFile.h
        LogFile.cpp
        LogStream.h
        LogStream.cpp
        AsyncLogging.h
        AsyncLogging.cpp
        Logging.h
        Logging.cpp
        Util.h
        Util.cpp
        Timer.h
        HttpMessage.h
        HttpMessage.cpp
        Timer.cpp
        Channel.h
        EventLoop.h
        Epoll.h
        EventLoopThread.h
        EventLoopThreadPool.h
        HttpServer.h
        HttpServer.cpp
        Channel.cpp
        Epoll.cpp
        EventLoop.cpp
        EventLoopThread.cpp
        EventLoopThreadPool.cpp)
find_package(Threads REQUIRED)
target_link_libraries(Fitz Threads::Threads)
