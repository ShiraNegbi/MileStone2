//
// Created by shay on 1/16/19.
//

#ifndef MILESTONE2_PRIORITYQUEUE_H
#define MILESTONE2_PRIORITYQUEUE_H

#include <queue>
#include <unordered_set>
#include <set>

template <class T>
class PriorityQueue{
private:
    std::set<T> prioritySet;
   // std::unordered_set<T> queueContent;
public:
     void push(T t);
     T pop();
     bool isEmpty();
     bool isContain(T t);
     //pop a specific element from the queue
     T remove(const T &t);
};


#endif //MILESTONE2_PRIORITYQUEUE_H
