//
// Created by shira on 1/16/19.
//

#ifndef MILESTONE2_SEARCHERSOLVER_H
#define MILESTONE2_SEARCHERSOLVER_H
#include <string>
#include "Solver.h"
#include "Searcher.h"
using namespace std;

template <class Problem, class Solution>
class SearcherSolver : public Solver<Problem, Solution> {
    Searcher<Problem, Solution>* searcher;
public:
    SearcherSolver(Searcher<Problem, Solution>* searcher);
    Solution solve(Problem problem) override;
};

template<class Problem, class Solution>
Solution SearcherSolver<Problem, Solution>::solve(Problem problem) override;

#endif //MILESTONE2_SEARCHERSOLVER_H
