//
// Created by shira on 1/9/19.
//

#ifndef MILESTONE2_SERVER_SIDE_H
#define MILESTONE2_SERVER_SIDE_H
#include "ClientHandler.h"

namespace server_side {
    class Server {
    public:
        virtual void open(int port, ClientHandler* clientHandler) = 0;
        virtual void stop() = 0;
    };
    namespace boot {
        class Main {
        public:
           int main(int argc, char* argv[]) {
                Server* server;

            }
        };
    }
}

#endif //MILESTONE2_SERVER_SIDE_H
