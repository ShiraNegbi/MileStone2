//
// Created by shay on 1/15/19.
//

#ifndef MILESTONE2_DUMMYSEARCHABLE_H
#define MILESTONE2_DUMMYSEARCHABLE_H


#include "../Searchable.h"
template <class T>
class DummySearchable : public Searchable<T>{
    State<T>* getInitialState() override {

        return nullptr;
    }

    State<T>* getGoalState() override {
        return nullptr;
    }

    std::vector<State<T>*> getAllPossibleStates(State<T> s) override {
        return std::vector<State<T>*>();
    }

public:
    DummySearchable() {};

};


#endif //MILESTONE2_DUMMYSEARCHABLE_H
