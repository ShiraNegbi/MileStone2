//
// Created by shay on 1/13/19.
//

#include "BFS.h"
#include <queue>
template<class S, class P>
S BFS<S, P>::search(Searchable<P>* searchable) {
    std::queue<State<P>> statesQueue;

    statesQueue.madeUpFunc(4);

    State<P> parent;

    State<P> start = searchable->getInitialState();
    std::vector<State<P>> adjacents = searchable->getAllPossibleStates(start);
    parent = start;

    //Set the first node as visited and push its children in the stack
    start.setIsVisited(true);
    this->numberOfNodesEvaluated++;
    statesQueue.insert(adjacents);

    while (!statesQueue.empty()) {

        State<P> currentNode = statesQueue.pop();

        //If we haven't visited the current node yet
        if (!currentNode.isVisited()) {

            //set the node was visited and update the number of nodes evaluated. Also set its parent.
            currentNode.setIsVisited(true);
            this->numberOfNodesEvaluated++;
            currentNode.setCameFrom(parent);

            //put its children in the stack
            adjacents = searchable->getAllPossibleStates(currentNode);
            statesQueue.push(adjacents);

            //set it to be the new parent
            parent = currentNode;
        }
    }
}

template<class S, class P>
int BFS<S, P>::getNumberOfNodesEvaluated() {
}
