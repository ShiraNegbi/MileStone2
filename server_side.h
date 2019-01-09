//
// Created by shira on 1/9/19.
//

#ifndef MILESTONE2_SERVER_SIDE_H
#define MILESTONE2_SERVER_SIDE_H
#include "ClientHandler.h"

namespace server_side {
    class Server {
    public:
        virtual void open(int port, ClientHandler clientHandler);
        virtual void stop();
    };
}

#endif //MILESTONE2_SERVER_SIDE_H
