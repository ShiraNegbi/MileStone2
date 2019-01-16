//
// Created by shira on 1/16/19.
//

#ifndef MILESTONE2_SERVERINFO_H
#define MILESTONE2_SERVERINFO_H
#include "ClientHandler.h"

class ServerInfo {
private:
    ClientHandler* clientHandler;
    int socketID;
    int portNumber;
public:
    ServerInfo(ClientHandler *clientHandler, int portNum, int socketID = 0);
    ClientHandler* getClientHandler();
    int getSocketID() const;
    int getPortNumber();
};

#endif //MILESTONE2_SERVERINFO_H
