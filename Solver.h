//
// Created by shira on 1/9/19.
//

#ifndef MILESTONE2_SOLVER_H
#define MILESTONE2_SOLVER_H
#include "Problem.h"
#include "Solution.h"

class Solver {
public:
    virtual Solution solve(Problem problem) = 0;
};

#endif //MILESTONE2_SOLVER_H
