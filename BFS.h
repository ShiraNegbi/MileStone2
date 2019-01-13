//
// Created by shay on 1/13/19.
//

#ifndef MILESTONE2_BFS_H
#define MILESTONE2_BFS_H


#include "Searcher.h"

template <class S,class P>
class BFS : public Searcher<P, S> {
    S search(Searchable<P>* searchable) override;

    int getNumberOfNodesEvaluated() override;
};


#endif //MILESTONE2_BFS_H
