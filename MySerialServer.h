//
// Created by shira on 1/9/19.
//

#ifndef MILESTONE2_MYSERIALSERVER_H
#define MILESTONE2_MYSERIALSERVER_H
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <cstdlib>
#include <iostream>
#include "server_side.h"

using namespace server_side;

class MySerialServer : public Server {
    int currentSocket;
    int s;
public:
    void open(int port, ClientHandler clientHandler) override;
    void stop() = override;
};

#endif //MILESTONE2_MYSERIALSERVER_H
