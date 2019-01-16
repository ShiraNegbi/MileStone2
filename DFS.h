//
// Created by shay on 1/12/19.
//

#ifndef MILESTONE2_DFS_H
#define MILESTONE2_DFS_H


#include "Searcher.h"
#include "GeneralFirstSearch.h"
#include <stack>
template<class P>
class DFS : public GeneralFirstSearch<P> {
private:
    std::stack<State<P>> statesStack;
protected:
    void pushToDataset(State<P> state) override;

    State<P> popFromDataset() override;

    bool isDatasetEmpty() override;

};


#endif //MILESTONE2_DFS_H
