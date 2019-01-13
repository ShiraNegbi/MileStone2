//
// Created by shay on 1/12/19.
//

#include "DFS.h"
#include <stack>


template<class P, class S>
S DFS<P, S>::search(Searchable<P>* searchable) {
    std::stack<State<P>> statesStack;

    State<P> start;
    std::vector<State<P>> adjacents;

    start = searchable->getInitialState();
    adjacents = searchable->getAllPossibleStates(start);
    statesStack.push(adjacents);

    while (!statesStack.empty()) {
        State<P> currentNode = statesStack.pop();
        if (currentNode == searchable->getGoalState()) {

        }
        currentNode.setIsVisited(true);

    }


}

template<class P, class S>
int DFS<P, S>::getNumberOfNodesEvaluated() {
    return 0;
}
