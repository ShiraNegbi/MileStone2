//
// Created by shira on 1/14/19.
//

#ifndef MILESTONE2_MYCLIENTHANDLER_H
#define MILESTONE2_MYCLIENTHANDLER_H
#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
#include "MatrixProblem.h"
#include <string>
#include <sstream>
#include <unistd.h>
#include <strings.h>
#include <vector>
#define BUFFER_SIZE 1024
using namespace std;

template <class Problem, class Solution>
class MyClientHandler : public ClientHandler {
    Solver<Problem, Solution>* solver;
    CacheManager<Problem, Solution>* cacheManager;
public:
    MyClientHandler(Solver<Problem, Solution>* solver, CacheManager<Problem, Solution>* cacheManager);
    virtual void handleClient(int input, int output) override;
};

#endif //MILESTONE2_MYCLIENTHANDLER_H
