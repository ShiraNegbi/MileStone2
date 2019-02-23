//
// Created by shira on 1/16/19.
//

#ifndef MILESTONE2_SEARCHERSOLVER_H
#define MILESTONE2_SEARCHERSOLVER_H

#include <string>
#include "Solver.h"
#include "Searcher.h"

using namespace std;

template<class P, class S>
class SearcherSolver : public Solver<Searchable<P>*, S> {
    Searcher<P, S>* searcher;
public:
    explicit SearcherSolver(Searcher<P, S>* searcher) {
        this->searcher = searcher;
    }

    S solve(Searchable<P>* problem) override {
        return this->searcher->search(problem);
    }
};


#endif //MILESTONE2_SEARCHERSOLVER_H
