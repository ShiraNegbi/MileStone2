//
// Created by shay on 1/16/19.
//

#include "PriorityQueue.h"

template<class T>
void PriorityQueue<T>::push(T t) {
    this->prioritySet.push(t);
    this->queueContent.insert(t);
}

template<class T>
T PriorityQueue<T>::pop() {
    if(prioritySet.empty()){
        throw "queue is empty and therefore cannot pop anything";
    }
    //pop out the smallest element in the set
    T* top = this->prioritySet.begin();
    this->prioritySet.erase(top);
    //this->queueContent.erase(top);


    return top;
}

template<class T>
bool PriorityQueue<T>::isEmpty() {
    return prioritySet.empty();
}

template<class T>
bool PriorityQueue<T>::isContain(T t) {
    return prioritySet.find(t) != prioritySet.end();
}

template<class T>
T PriorityQueue<T>::remove(const T &t) {
    if(prioritySet.find(t)){
        prioritySet.erase(t);
        //queueContent.erase(t);
    }
    throw "Item not in the priority queue. Are you sure your algorithm is right?";
}


