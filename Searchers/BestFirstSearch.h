//
// Created by shay on 1/13/19.
//

#ifndef MILESTONE2_BESTFIRSTSEARCH_H
#define MILESTONE2_BESTFIRSTSEARCH_H


#include "../Searcher.h"
template <class P, class S>
class BestFirstSearch : public Searcher<P,S> {
    S search(Searchable<P>* searchable) override;

    int getNumberOfNodesEvaluated() override;

};


#endif //MILESTONE2_BESTFIRSTSEARCH_H