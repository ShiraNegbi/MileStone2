//
// Created by shira on 1/9/19.
//

#ifndef MILESTONE2_CLIENTHANDLER_H
#define MILESTONE2_CLIENTHANDLER_H

class ClientHandler {
public:
    virtual void handleClient(int input, int output) = 0; // int of socket id
};

#endif //MILESTONE2_CLIENTHANDLER_H
