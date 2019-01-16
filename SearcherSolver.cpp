//
// Created by shira on 1/16/19.
//

#include "SearcherSolver.h"

template<class Problem, class Solution>
SearcherSolver<Problem, Solution>::SearcherSolver(Searcher<Problem, Solution>* searcher) {
    this->searcher = searcher;
}

template<class Problem, class Solution>
Solution SearcherSolver<Problem, Solution>::solve(Problem problem) {
    return this->searcher->search(&problem);
}
