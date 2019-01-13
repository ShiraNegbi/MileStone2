//
// Created by shay on 1/12/19.
//

#include "DFS.h"
#include <stack>


template<class P, class S>
S DFS<P, S>::search(Searchable<P>* searchable) {
    std::stack<State<P>> statesStack;
    State<P> parent;

    State<P> start = searchable->getInitialState();
    std::vector<State<P>> adjacents = searchable->getAllPossibleStates(start);
    parent = start;

    //Set the first node as visited and push its children in the stack
    start.setIsVisited(true);
    this->numberOfNodesEvaluated++;
    statesStack.push(adjacents);

    while (!statesStack.empty()) {

        State<P> currentNode = statesStack.pop();

        //If we haven't visited the current node yet
        if (!currentNode.isVisited()) {

            //set the node was visited and update the number of nodes evaluated. Also set its parent.
            currentNode.setIsVisited(true);
            this->numberOfNodesEvaluated++;
            currentNode.setCameFrom(parent);

            //put its children in the stack
            adjacents = searchable->getAllPossibleStates(currentNode);
            statesStack.push(adjacents);

            //set it to be the new parent
            parent = currentNode;
        }
    }
    //todo: write the return value


}

template<class P, class S>
int DFS<P, S>::getNumberOfNodesEvaluated() {
    return 0;
}
