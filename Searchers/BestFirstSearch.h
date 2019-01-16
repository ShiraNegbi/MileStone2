//
// Created by shay on 1/13/19.
//

#ifndef MILESTONE2_BESTFIRSTSEARCH_H
#define MILESTONE2_BESTFIRSTSEARCH_H


#include "../Searcher.h"
#include <unordered_set>
#include <queue>
#include "../PriorityQueue.h"

template<class P>
class BestFirstSearch : public Searcher<P, State<P>*> {
private:
    int numberOfNodesEvaluated;
public:
    State<P>* search(Searchable<P>* searchable) override {
        /*An unordered set that contains the same elements as "open",
        so we can check which element is in "open" in O(1) time. */
        PriorityQueue<State<P>*> open; //the priority queue named "open"
        std::unordered_set<State<P>*> close;


        State<P>* initial = searchable->getInitialState();
        State<P>* goalState = searchable->getGoalState();

        open.push(initial);

        while (!open.isEmpty()) {
            State<P>* n = open.pop();
            this->numberOfNodesEvaluated++;
            close.insert(n);
            if (n == goalState) {
                return n;
            }
            for (State<P>* successor : searchable->getAllPossibleStates(n)) {

                double totalCost = n->getTotalCost() + successor->getCost();
                //if the successor is not in "close" or "open"
                if (close.find(successor) != close.end() && !open.isContain(successor)) {
                    successor->setCameFrom(n);
                    successor->setTotalCost(totalCost);
                    open.push(successor);
                } else if (totalCost > successor->getTotalCost()) {
                    open.remove(successor);
                    successor->setTotalCost(totalCost);
                    successor->setCameFrom(n);
                    open.push(successor);
                }
            }
        }
    }

    int getNumberOfNodesEvaluated() override {
        return this->numberOfNodesEvaluated;
    }

protected:
    virtual double calculateDistance(State<P>* state, State<P>* cameFrom) {
        return cameFrom->getTotalCost() + state->getCost();
    }
};


#endif //MILESTONE2_BESTFIRSTSEARCH_H
