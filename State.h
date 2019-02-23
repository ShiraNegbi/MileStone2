//
// Created by shay on 1/12/19.
//

#ifndef MILESTONE2_STATE_H
#define MILESTONE2_STATE_H

#include <string>

template<class T>
class State {

private:
    T value;
    double originalCost;


    State<T>* cameFrom;
    bool visited;
    double totalCost;

public:

    State(T state, double cost, State<T>* cameFrom, bool visited) : value(value), originalCost(cost),
                                                                    cameFrom(cameFrom),
                                                                    visited(visited) {}

    T getValue() const {
        return value;
    }

    double getCost() const {
        return originalCost;
    }

    State<T>* getCameFrom() const {
        return cameFrom;
    }

    double getTotalCost() const {
        return totalCost;
    }

    bool isVisited() const {
        return visited;
    }

    void setValue(T state) {
        value = state;
    }

    void setCost(double cost) {
        originalCost = cost;
    }

    void setCameFrom(State<T>* cameFrom) {
        State::cameFrom = cameFrom;
    }

    void setIsVisited(bool visited) {
        State::visited = visited;
    }

    void setTotalCost(double totalCost) {
        State::totalCost = totalCost;
    }
//    std::string toString() {
//        return "yay";
//    }
};


#endif //MILESTONE2_STATE_H
