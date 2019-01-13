//
// Created by shay on 1/12/19.
//

#include "State.h"

template<class T>
State<T>::State(T state, double cost, State<T>* cameFrom, bool visited) : state(state), cost(cost), cameFrom(cameFrom),
                                                                          visited(visited) {}

template<class T>
T State<T>::getState() const {
    return state;
}

template<class T>
double State<T>::getCost() const {
    return cost;
}

template<class T>
State<T>* State<T>::getCameFrom() const {
    return cameFrom;
}

template<class T>
bool State<T>::isVisited() const {
    return visited;
}

template<class T>
void State<T>::setState(T state) {
    State::state = state;
}

template<class T>
void State<T>::setCost(double cost) {
    State::cost = cost;
}

template<class T>
void State<T>::setCameFrom(State<T>* cameFrom) {
    State::cameFrom = cameFrom;
}

template<class T>
void State<T>::setIsVisited(bool visited) {
    State::visited = visited;
}
