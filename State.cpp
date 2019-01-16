//
// Created by shay on 1/12/19.
//

#include "State.h"

template<class T>
State<T>::State(T value, double cost, State<T>* cameFrom, bool visited) : value(value), originalCost(cost), cameFrom(cameFrom),
                                                                          visited(visited) {}

template<class T>
T State<T>::getValue() const {
    return value;
}

template<class T>
double State<T>::getCost() const {
    return originalCost;
}

template<class T>
State<T>* State<T>::getCameFrom() const {
    return cameFrom;
}
template<class T>
double State<T>::getTotalCost() const {
    return totalCost;
}

template<class T>
bool State<T>::isVisited() const {
    return visited;
}

template<class T>
void State<T>::setValue(T state) {
    State::value = state;
}

template<class T>
void State<T>::setCost(double cost) {
    State::originalCost = cost;
}

template<class T>
void State<T>::setCameFrom(State<T>* cameFrom) {
    State::cameFrom = cameFrom;
}

template<class T>
void State<T>::setIsVisited(bool visited) {
    State::visited = visited;
}

template<class T>
void State<T>::setTotalCost(double totalCost) {
    State::totalCost = totalCost;
}

