//
// Created by shay on 1/14/19.
//

#ifndef MILESTONE2_GENERALFIRSTSEARCH_H
#define MILESTONE2_GENERALFIRSTSEARCH_H

#include "../Searcher.h"

/**
 * This virtual class is a general version of algorithms like DFS and BFS,
 * or any other algorithm that uses a data structure with push and pop behaviour.
 *
 * It has the general implementation of those algorithms, but the specific dataset will be chosen by the class
 * that inherits it, and is expected to be a private member in it.
 */
template<class P>
class GeneralFirstSearch : Searcher<P, State<P>> {
     State<P> search(Searchable<P>* searchable) override;

    int getNumberOfNodesEvaluated() override;

protected:
    //push a state to a private data structure of your choice
    virtual void pushToDataset(State<P>) = 0;
    //pop a state from the data structure
    virtual State<P> popFromDataset() = 0;
    //check if your data structure is empty
    virtual bool isDatasetEmpty() = 0;
};


#endif //MILESTONE2_GENERALFIRSTSEARCH_H
