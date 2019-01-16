//
// Created by shay on 1/12/19.
//

#ifndef MILESTONE2_SEARCHER_H
#define MILESTONE2_SEARCHER_H


#include "Searchable.h"

template<class P, class S>
class Searcher {
public:
    virtual S search(Searchable<P>* searchable) = 0;
    //get how many nodes were evaluated by the algorithm
    virtual int getNumberOfNodesEvaluated() = 0;
};


#endif //MILESTONE2_SEARCHER_H
