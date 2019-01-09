//
// Created by shira on 1/9/19.
//

#ifndef MILESTONE2_MYTESTCLIENTHANDLER_H
#define MILESTONE2_MYTESTCLIENTHANDLER_H
#include "ClientHandler.h"
#include "Solver.h"
#include "CacheManager.h"

class MyTestClientHandler : public ClientHandler {
Solver* solver;
CacheManager* cacheManager;
};

#endif //MILESTONE2_MYTESTCLIENTHANDLER_H