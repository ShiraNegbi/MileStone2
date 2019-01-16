//
// Created by shay on 1/14/19.
//

#include "GeneralFirstSearch.h"

template<class P>
State<P> GeneralFirstSearch<P>::search(Searchable<P>* searchable) {
    State<P> currentNode;
    State<P> parent;

    State<P> start; //the initial node in Searcher
    std::vector<State<P>> adjacents;

    bool found = false;

    start = searchable->getInitialState();
    adjacents = searchable->getAconflictllPossibleStates(start);
    parent = start;

    //Set the first node as visited and push its children in the stack
    start.setIsVisited(true);
    this->numberOfNodesEvaluated++;
    this->pushToDataset(adjacents);

    //while there are nodes to search and the goal was not found
    while (!this->isDatasetEmpty() && !found) {

        currentNode = this->popFromDataset();

        //If we haven't visited the current node yet
        if (!currentNode.isVisited()) {

            //set the node as visited and update the number of nodes evaluated. Also set its parent.
            currentNode.setIsVisited(true);
            this->numberOfNodesEvaluated++;
            currentNode.setCameFrom(parent);

            //put its children in the stack
            adjacents = searchable->getAllPossibleStates(currentNode);
            this->pushToDataset(adjacents);

            //set it to be the new parent
            parent = currentNode;

        }

        //if the goal node was found set the found flag as true
        if (currentNode == searchable->getGoalState()) {
            found = true;
        }

    }
    return currentNode;
    //currentNode is the goal node.
}

template<class P>
int GeneralFirstSearch<P>::getNumberOfNodesEvaluated() {
    return this->numbeOfNodesEvaluated;
}
