//
// Created by shira on 1/9/19.
//

#ifndef MILESTONE2_MYTESTCLIENTHANDLER_H
#define MILESTONE2_MYTESTCLIENTHANDLER_H
#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
#include <string>
#include <sstream>
#include <unistd.h>
#include <strings.h>
#define BUFFER_SIZE 1024
using namespace std;

class MyTestClientHandler : public ClientHandler {
Solver<Problem, Solution>* solver;
CacheManager* cacheManager;
public:
    MyTestClientHandler(Solver<Problem, Solution>* solver, CacheManager* cacheManager);
    virtual void handleClient(int input, int output) override;
};

#endif //MILESTONE2_MYTESTCLIENTHANDLER_H
