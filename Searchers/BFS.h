//
// Created by shay on 1/15/19.
//

#ifndef MILESTONE2_BFS_H
#define MILESTONE2_BFS_H


#include <queue>
#include "GeneralFirstSearch.h"
template <class P>
class BFS : public GeneralFirstSearch<P>{
private:
    std::queue<State<P>> statesQueue;
public:
    void pushToDataset(State<P> state) override;

    State<P> popFromDataset() override;

    bool isDatasetEmpty() override;
};


#endif //MILESTONE2_BFS_H
