//
// Created by shay on 1/16/19.
//

#ifndef MILESTONE2_PRIORITYQUEUE_H
#define MILESTONE2_PRIORITYQUEUE_H

#include <queue>
#include <unordered_set>
#include <set>

template<class T>
/**
 * A more convinient priority queue I wrote, which supports removing a specific element from the queue.
 * @tparam T any kind of variable
 */
class PriorityQueue {
private:
    std::set<T> prioritySet;
public:
    void push(T t) {
        this->prioritySet.insert(t);
       // this->queueContent.insert(t);
    }

    T pop() {
        if (prioritySet.empty()) {
            throw "queue is empty and therefore cannot pop anything";
        }
        //pop out the smallest element in the set
        T top = *(this->prioritySet.begin());
       // this->prioritySet.erase(top);


        return top;
    }

    bool isEmpty() {
        return prioritySet.empty();
    }

    bool isContain(T t) {
        return prioritySet.find(t) != prioritySet.end();
    }

    //pop a specific element from the queue
    T remove(const T &t) {
        if (prioritySet.find(t) != prioritySet.end()) {
            prioritySet.erase(t);
            //queueContent.erase(t);
        } else {
            throw "Item not in the priority queue. Are you sure your algorithm is right?";
        }
    }
};


#endif //MILESTONE2_PRIORITYQUEUE_H
