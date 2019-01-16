//
// Created by shay on 1/13/19.
//

#ifndef MILESTONE2_ASTAR_H
#define MILESTONE2_ASTAR_H

#include "../Searcher.h"
#include "BestFirstSearch.h"


template<class P>
class AStar : BestFirstSearch<P> {
    double calculateDistance(State<P>* state, State<P>* cameFrom, State<P>* goal) override {

        int x1 = state->getState().first;
        int y1 = state->getState().second;
        int x2 = goal->getState().first;
        int y2 = goal->getState().second;

        double distanceToEnd = abs(y2 - y1) + abs(x2 - x1);
        return BestFirstSearch<P>::calculateDistance(state, cameFrom, goal) + distanceToEnd;
    }
};


#endif //MILESTONE2_ASTAR_H
