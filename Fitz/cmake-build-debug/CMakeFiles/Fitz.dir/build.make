# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/py/文档/clion-2020.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/py/文档/clion-2020.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/py/CLionProjects/Fitz

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/py/CLionProjects/Fitz/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Fitz.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Fitz.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Fitz.dir/flags.make

CMakeFiles/Fitz.dir/main.cpp.o: CMakeFiles/Fitz.dir/flags.make
CMakeFiles/Fitz.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/py/CLionProjects/Fitz/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Fitz.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Fitz.dir/main.cpp.o -c /home/py/CLionProjects/Fitz/main.cpp

CMakeFiles/Fitz.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Fitz.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/py/CLionProjects/Fitz/main.cpp > CMakeFiles/Fitz.dir/main.cpp.i

CMakeFiles/Fitz.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Fitz.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/py/CLionProjects/Fitz/main.cpp -o CMakeFiles/Fitz.dir/main.cpp.s

CMakeFiles/Fitz.dir/CountDownLatch.cpp.o: CMakeFiles/Fitz.dir/flags.make
CMakeFiles/Fitz.dir/CountDownLatch.cpp.o: ../CountDownLatch.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/py/CLionProjects/Fitz/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Fitz.dir/CountDownLatch.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Fitz.dir/CountDownLatch.cpp.o -c /home/py/CLionProjects/Fitz/CountDownLatch.cpp

CMakeFiles/Fitz.dir/CountDownLatch.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Fitz.dir/CountDownLatch.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/py/CLionProjects/Fitz/CountDownLatch.cpp > CMakeFiles/Fitz.dir/CountDownLatch.cpp.i

CMakeFiles/Fitz.dir/CountDownLatch.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Fitz.dir/CountDownLatch.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/py/CLionProjects/Fitz/CountDownLatch.cpp -o CMakeFiles/Fitz.dir/CountDownLatch.cpp.s

CMakeFiles/Fitz.dir/Thread.cpp.o: CMakeFiles/Fitz.dir/flags.make
CMakeFiles/Fitz.dir/Thread.cpp.o: ../Thread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/py/CLionProjects/Fitz/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Fitz.dir/Thread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Fitz.dir/Thread.cpp.o -c /home/py/CLionProjects/Fitz/Thread.cpp

CMakeFiles/Fitz.dir/Thread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Fitz.dir/Thread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/py/CLionProjects/Fitz/Thread.cpp > CMakeFiles/Fitz.dir/Thread.cpp.i

CMakeFiles/Fitz.dir/Thread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Fitz.dir/Thread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/py/CLionProjects/Fitz/Thread.cpp -o CMakeFiles/Fitz.dir/Thread.cpp.s

CMakeFiles/Fitz.dir/FileUtil.cpp.o: CMakeFiles/Fitz.dir/flags.make
CMakeFiles/Fitz.dir/FileUtil.cpp.o: ../FileUtil.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/py/CLionProjects/Fitz/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Fitz.dir/FileUtil.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Fitz.dir/FileUtil.cpp.o -c /home/py/CLionProjects/Fitz/FileUtil.cpp

CMakeFiles/Fitz.dir/FileUtil.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Fitz.dir/FileUtil.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/py/CLionProjects/Fitz/FileUtil.cpp > CMakeFiles/Fitz.dir/FileUtil.cpp.i

CMakeFiles/Fitz.dir/FileUtil.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Fitz.dir/FileUtil.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/py/CLionProjects/Fitz/FileUtil.cpp -o CMakeFiles/Fitz.dir/FileUtil.cpp.s

CMakeFiles/Fitz.dir/LogFile.cpp.o: CMakeFiles/Fitz.dir/flags.make
CMakeFiles/Fitz.dir/LogFile.cpp.o: ../LogFile.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/py/CLionProjects/Fitz/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Fitz.dir/LogFile.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Fitz.dir/LogFile.cpp.o -c /home/py/CLionProjects/Fitz/LogFile.cpp

CMakeFiles/Fitz.dir/LogFile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Fitz.dir/LogFile.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/py/CLionProjects/Fitz/LogFile.cpp > CMakeFiles/Fitz.dir/LogFile.cpp.i

CMakeFiles/Fitz.dir/LogFile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Fitz.dir/LogFile.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/py/CLionProjects/Fitz/LogFile.cpp -o CMakeFiles/Fitz.dir/LogFile.cpp.s

CMakeFiles/Fitz.dir/LogStream.cpp.o: CMakeFiles/Fitz.dir/flags.make
CMakeFiles/Fitz.dir/LogStream.cpp.o: ../LogStream.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/py/CLionProjects/Fitz/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Fitz.dir/LogStream.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Fitz.dir/LogStream.cpp.o -c /home/py/CLionProjects/Fitz/LogStream.cpp

CMakeFiles/Fitz.dir/LogStream.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Fitz.dir/LogStream.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/py/CLionProjects/Fitz/LogStream.cpp > CMakeFiles/Fitz.dir/LogStream.cpp.i

CMakeFiles/Fitz.dir/LogStream.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Fitz.dir/LogStream.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/py/CLionProjects/Fitz/LogStream.cpp -o CMakeFiles/Fitz.dir/LogStream.cpp.s

CMakeFiles/Fitz.dir/AsyncLogging.cpp.o: CMakeFiles/Fitz.dir/flags.make
CMakeFiles/Fitz.dir/AsyncLogging.cpp.o: ../AsyncLogging.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/py/CLionProjects/Fitz/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Fitz.dir/AsyncLogging.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Fitz.dir/AsyncLogging.cpp.o -c /home/py/CLionProjects/Fitz/AsyncLogging.cpp

CMakeFiles/Fitz.dir/AsyncLogging.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Fitz.dir/AsyncLogging.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/py/CLionProjects/Fitz/AsyncLogging.cpp > CMakeFiles/Fitz.dir/AsyncLogging.cpp.i

CMakeFiles/Fitz.dir/AsyncLogging.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Fitz.dir/AsyncLogging.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/py/CLionProjects/Fitz/AsyncLogging.cpp -o CMakeFiles/Fitz.dir/AsyncLogging.cpp.s

CMakeFiles/Fitz.dir/Logging.cpp.o: CMakeFiles/Fitz.dir/flags.make
CMakeFiles/Fitz.dir/Logging.cpp.o: ../Logging.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/py/CLionProjects/Fitz/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Fitz.dir/Logging.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Fitz.dir/Logging.cpp.o -c /home/py/CLionProjects/Fitz/Logging.cpp

CMakeFiles/Fitz.dir/Logging.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Fitz.dir/Logging.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/py/CLionProjects/Fitz/Logging.cpp > CMakeFiles/Fitz.dir/Logging.cpp.i

CMakeFiles/Fitz.dir/Logging.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Fitz.dir/Logging.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/py/CLionProjects/Fitz/Logging.cpp -o CMakeFiles/Fitz.dir/Logging.cpp.s

CMakeFiles/Fitz.dir/Util.cpp.o: CMakeFiles/Fitz.dir/flags.make
CMakeFiles/Fitz.dir/Util.cpp.o: ../Util.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/py/CLionProjects/Fitz/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Fitz.dir/Util.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Fitz.dir/Util.cpp.o -c /home/py/CLionProjects/Fitz/Util.cpp

CMakeFiles/Fitz.dir/Util.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Fitz.dir/Util.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/py/CLionProjects/Fitz/Util.cpp > CMakeFiles/Fitz.dir/Util.cpp.i

CMakeFiles/Fitz.dir/Util.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Fitz.dir/Util.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/py/CLionProjects/Fitz/Util.cpp -o CMakeFiles/Fitz.dir/Util.cpp.s

CMakeFiles/Fitz.dir/HttpMessage.cpp.o: CMakeFiles/Fitz.dir/flags.make
CMakeFiles/Fitz.dir/HttpMessage.cpp.o: ../HttpMessage.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/py/CLionProjects/Fitz/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Fitz.dir/HttpMessage.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Fitz.dir/HttpMessage.cpp.o -c /home/py/CLionProjects/Fitz/HttpMessage.cpp

CMakeFiles/Fitz.dir/HttpMessage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Fitz.dir/HttpMessage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/py/CLionProjects/Fitz/HttpMessage.cpp > CMakeFiles/Fitz.dir/HttpMessage.cpp.i

CMakeFiles/Fitz.dir/HttpMessage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Fitz.dir/HttpMessage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/py/CLionProjects/Fitz/HttpMessage.cpp -o CMakeFiles/Fitz.dir/HttpMessage.cpp.s

CMakeFiles/Fitz.dir/Timer.cpp.o: CMakeFiles/Fitz.dir/flags.make
CMakeFiles/Fitz.dir/Timer.cpp.o: ../Timer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/py/CLionProjects/Fitz/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Fitz.dir/Timer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Fitz.dir/Timer.cpp.o -c /home/py/CLionProjects/Fitz/Timer.cpp

CMakeFiles/Fitz.dir/Timer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Fitz.dir/Timer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/py/CLionProjects/Fitz/Timer.cpp > CMakeFiles/Fitz.dir/Timer.cpp.i

CMakeFiles/Fitz.dir/Timer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Fitz.dir/Timer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/py/CLionProjects/Fitz/Timer.cpp -o CMakeFiles/Fitz.dir/Timer.cpp.s

CMakeFiles/Fitz.dir/HttpServer.cpp.o: CMakeFiles/Fitz.dir/flags.make
CMakeFiles/Fitz.dir/HttpServer.cpp.o: ../HttpServer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/py/CLionProjects/Fitz/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Fitz.dir/HttpServer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Fitz.dir/HttpServer.cpp.o -c /home/py/CLionProjects/Fitz/HttpServer.cpp

CMakeFiles/Fitz.dir/HttpServer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Fitz.dir/HttpServer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/py/CLionProjects/Fitz/HttpServer.cpp > CMakeFiles/Fitz.dir/HttpServer.cpp.i

CMakeFiles/Fitz.dir/HttpServer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Fitz.dir/HttpServer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/py/CLionProjects/Fitz/HttpServer.cpp -o CMakeFiles/Fitz.dir/HttpServer.cpp.s

CMakeFiles/Fitz.dir/Channel.cpp.o: CMakeFiles/Fitz.dir/flags.make
CMakeFiles/Fitz.dir/Channel.cpp.o: ../Channel.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/py/CLionProjects/Fitz/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Fitz.dir/Channel.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Fitz.dir/Channel.cpp.o -c /home/py/CLionProjects/Fitz/Channel.cpp

CMakeFiles/Fitz.dir/Channel.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Fitz.dir/Channel.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/py/CLionProjects/Fitz/Channel.cpp > CMakeFiles/Fitz.dir/Channel.cpp.i

CMakeFiles/Fitz.dir/Channel.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Fitz.dir/Channel.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/py/CLionProjects/Fitz/Channel.cpp -o CMakeFiles/Fitz.dir/Channel.cpp.s

CMakeFiles/Fitz.dir/Epoll.cpp.o: CMakeFiles/Fitz.dir/flags.make
CMakeFiles/Fitz.dir/Epoll.cpp.o: ../Epoll.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/py/CLionProjects/Fitz/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Fitz.dir/Epoll.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Fitz.dir/Epoll.cpp.o -c /home/py/CLionProjects/Fitz/Epoll.cpp

CMakeFiles/Fitz.dir/Epoll.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Fitz.dir/Epoll.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/py/CLionProjects/Fitz/Epoll.cpp > CMakeFiles/Fitz.dir/Epoll.cpp.i

CMakeFiles/Fitz.dir/Epoll.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Fitz.dir/Epoll.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/py/CLionProjects/Fitz/Epoll.cpp -o CMakeFiles/Fitz.dir/Epoll.cpp.s

CMakeFiles/Fitz.dir/EventLoop.cpp.o: CMakeFiles/Fitz.dir/flags.make
CMakeFiles/Fitz.dir/EventLoop.cpp.o: ../EventLoop.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/py/CLionProjects/Fitz/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/Fitz.dir/EventLoop.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Fitz.dir/EventLoop.cpp.o -c /home/py/CLionProjects/Fitz/EventLoop.cpp

CMakeFiles/Fitz.dir/EventLoop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Fitz.dir/EventLoop.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/py/CLionProjects/Fitz/EventLoop.cpp > CMakeFiles/Fitz.dir/EventLoop.cpp.i

CMakeFiles/Fitz.dir/EventLoop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Fitz.dir/EventLoop.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/py/CLionProjects/Fitz/EventLoop.cpp -o CMakeFiles/Fitz.dir/EventLoop.cpp.s

CMakeFiles/Fitz.dir/EventLoopThread.cpp.o: CMakeFiles/Fitz.dir/flags.make
CMakeFiles/Fitz.dir/EventLoopThread.cpp.o: ../EventLoopThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/py/CLionProjects/Fitz/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/Fitz.dir/EventLoopThread.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Fitz.dir/EventLoopThread.cpp.o -c /home/py/CLionProjects/Fitz/EventLoopThread.cpp

CMakeFiles/Fitz.dir/EventLoopThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Fitz.dir/EventLoopThread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/py/CLionProjects/Fitz/EventLoopThread.cpp > CMakeFiles/Fitz.dir/EventLoopThread.cpp.i

CMakeFiles/Fitz.dir/EventLoopThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Fitz.dir/EventLoopThread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/py/CLionProjects/Fitz/EventLoopThread.cpp -o CMakeFiles/Fitz.dir/EventLoopThread.cpp.s

CMakeFiles/Fitz.dir/EventLoopThreadPool.cpp.o: CMakeFiles/Fitz.dir/flags.make
CMakeFiles/Fitz.dir/EventLoopThreadPool.cpp.o: ../EventLoopThreadPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/py/CLionProjects/Fitz/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/Fitz.dir/EventLoopThreadPool.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Fitz.dir/EventLoopThreadPool.cpp.o -c /home/py/CLionProjects/Fitz/EventLoopThreadPool.cpp

CMakeFiles/Fitz.dir/EventLoopThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Fitz.dir/EventLoopThreadPool.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/py/CLionProjects/Fitz/EventLoopThreadPool.cpp > CMakeFiles/Fitz.dir/EventLoopThreadPool.cpp.i

CMakeFiles/Fitz.dir/EventLoopThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Fitz.dir/EventLoopThreadPool.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/py/CLionProjects/Fitz/EventLoopThreadPool.cpp -o CMakeFiles/Fitz.dir/EventLoopThreadPool.cpp.s

# Object files for target Fitz
Fitz_OBJECTS = \
"CMakeFiles/Fitz.dir/main.cpp.o" \
"CMakeFiles/Fitz.dir/CountDownLatch.cpp.o" \
"CMakeFiles/Fitz.dir/Thread.cpp.o" \
"CMakeFiles/Fitz.dir/FileUtil.cpp.o" \
"CMakeFiles/Fitz.dir/LogFile.cpp.o" \
"CMakeFiles/Fitz.dir/LogStream.cpp.o" \
"CMakeFiles/Fitz.dir/AsyncLogging.cpp.o" \
"CMakeFiles/Fitz.dir/Logging.cpp.o" \
"CMakeFiles/Fitz.dir/Util.cpp.o" \
"CMakeFiles/Fitz.dir/HttpMessage.cpp.o" \
"CMakeFiles/Fitz.dir/Timer.cpp.o" \
"CMakeFiles/Fitz.dir/HttpServer.cpp.o" \
"CMakeFiles/Fitz.dir/Channel.cpp.o" \
"CMakeFiles/Fitz.dir/Epoll.cpp.o" \
"CMakeFiles/Fitz.dir/EventLoop.cpp.o" \
"CMakeFiles/Fitz.dir/EventLoopThread.cpp.o" \
"CMakeFiles/Fitz.dir/EventLoopThreadPool.cpp.o"

# External object files for target Fitz
Fitz_EXTERNAL_OBJECTS =

Fitz: CMakeFiles/Fitz.dir/main.cpp.o
Fitz: CMakeFiles/Fitz.dir/CountDownLatch.cpp.o
Fitz: CMakeFiles/Fitz.dir/Thread.cpp.o
Fitz: CMakeFiles/Fitz.dir/FileUtil.cpp.o
Fitz: CMakeFiles/Fitz.dir/LogFile.cpp.o
Fitz: CMakeFiles/Fitz.dir/LogStream.cpp.o
Fitz: CMakeFiles/Fitz.dir/AsyncLogging.cpp.o
Fitz: CMakeFiles/Fitz.dir/Logging.cpp.o
Fitz: CMakeFiles/Fitz.dir/Util.cpp.o
Fitz: CMakeFiles/Fitz.dir/HttpMessage.cpp.o
Fitz: CMakeFiles/Fitz.dir/Timer.cpp.o
Fitz: CMakeFiles/Fitz.dir/HttpServer.cpp.o
Fitz: CMakeFiles/Fitz.dir/Channel.cpp.o
Fitz: CMakeFiles/Fitz.dir/Epoll.cpp.o
Fitz: CMakeFiles/Fitz.dir/EventLoop.cpp.o
Fitz: CMakeFiles/Fitz.dir/EventLoopThread.cpp.o
Fitz: CMakeFiles/Fitz.dir/EventLoopThreadPool.cpp.o
Fitz: CMakeFiles/Fitz.dir/build.make
Fitz: CMakeFiles/Fitz.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/py/CLionProjects/Fitz/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Linking CXX executable Fitz"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Fitz.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Fitz.dir/build: Fitz

.PHONY : CMakeFiles/Fitz.dir/build

CMakeFiles/Fitz.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Fitz.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Fitz.dir/clean

CMakeFiles/Fitz.dir/depend:
	cd /home/py/CLionProjects/Fitz/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/py/CLionProjects/Fitz /home/py/CLionProjects/Fitz /home/py/CLionProjects/Fitz/cmake-build-debug /home/py/CLionProjects/Fitz/cmake-build-debug /home/py/CLionProjects/Fitz/cmake-build-debug/CMakeFiles/Fitz.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Fitz.dir/depend
