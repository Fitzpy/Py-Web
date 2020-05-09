#include <string>
#include "EventLoop.h"
#include "HttpServer.h"
#include "Logging.h"

int main(int argc, char *argv[]) {
    int threadNum = 4;
    int port = 10086;
    std::string logPath = "./WebServer.log";
    Logger::setLogFileName(logPath);
    EventLoop mainLoop;
    HttpServer myHTTPServer(&mainLoop, threadNum, port);
    myHTTPServer.start();
    mainLoop.loop();
    return 0;
}
