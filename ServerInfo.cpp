//
// Created by shira on 1/16/19.
//

#include "ServerInfo.h"

ServerInfo::ServerInfo(ClientHandler* clientHandler, int portNum, int socketID) {
    this->clientHandler = clientHandler;
    this->portNumber = portNum;
    this->socketID = socketID;
}

ClientHandler* ServerInfo::getClientHandler() {
    return this->clientHandler;
}

int ServerInfo::getSocketID() const {
    return socketID;
}

int ServerInfo::getPortNumber() {
    return this->portNumber;
}
