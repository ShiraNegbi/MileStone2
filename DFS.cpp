//
// Created by shay on 1/12/19.
//

#include "DFS.h"
#include <stack>


template<class P>
void DFS<P>::pushToDataset(State<P> state) {
    this->statesStack.push(state);
}

template<class P>
State<P> DFS<P>::popFromDataset() {
    this->statesStack.pop();
}

template<class P>
bool DFS<P>::isDatasetEmpty() {
    this->statesStack.empty();
}
