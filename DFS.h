//
// Created by shay on 1/12/19.
//

#ifndef MILESTONE2_DFS_H
#define MILESTONE2_DFS_H


#include "Searcher.h"

template<class P, class S>
class DFS : public Searcher<P, S> {
private:
    int numberOfNodesEvaluated;
    //a flag that checks if we ran the algorithm. If we didn't, we can't answer to getNumberOfNodesEvaluated.
    bool isRun;
public:
    S search(Searchable<P>* searchable) override;
    int getNumberOfNodesEvaluated() override;


};


#endif //MILESTONE2_DFS_H
