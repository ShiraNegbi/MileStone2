//
// Created by shay on 1/15/19.
//

#include "BFS.h"

template<class P>
void BFS<P>::pushToDataset(State<P> state) {
statesQueue.push(state);
}

template<class P>
State<P> BFS<P>::popFromDataset() {
    return statesQueue.pop();
}

template<class P>
bool BFS<P>::isDatasetEmpty() {
    return statesQueue.empty();
}
