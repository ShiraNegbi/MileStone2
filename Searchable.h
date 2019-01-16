//
// Created by shay on 1/12/19.
//

#ifndef MILESTONE2_SEARCHABLE_H
#define MILESTONE2_SEARCHABLE_H
#include <vector>
#include "State.h"
template <class T>
class Searchable {
public:
    virtual State<T>* getInitialState() = 0;
    virtual State<T>* getGoalState() = 0;
    virtual std::vector<State<T>*> getAllPossibleStates(State<T>* s) = 0;
   // virtual ~Searchable() = default;
};


#endif //MILESTONE2_SEARCHABLE_H
