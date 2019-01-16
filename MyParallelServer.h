//
// Created by shira on 1/16/19.
//

#ifndef MILESTONE2_MYPARALLELSERVER_H
#define MILESTONE2_MYPARALLELSERVER_H
#include <vector>
#include <thread>
#include <pthread.h>
#include <string.h>
#include <string>
#include <sstream>
#include <mutex>
#include <netinet/in.h>
#include "ClientHandler.h"
#include "ServerInfo.h"
#include "server_side.h"
using namespace server_side;
static std::mutex mutex;

class MyParallelServer : public Server {
private:
    std::vector<pthread_t*> threads;
public:
    void open(int port, ClientHandler *clientHandler) override;
    void stop() override;
private:
    static void* handle(void*);
};

#endif //MILESTONE2_MYPARALLELSERVER_H
