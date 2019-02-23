//
// Created by shira on 1/9/19.
//

#ifndef MILESTONE2_CACHMANAGER_H
#define MILESTONE2_CACHMANAGER_H

#include "string"
using std::string;
//template <class Problem, class Solution>
class CacheManager {
public:
    virtual bool hasSolution(string problem) = 0;
    virtual string getSolution(string problem) = 0;
    virtual void saveSolution(string problem, string solution) = 0;
};

#endif //MILESTONE2_CACHMANAGER_H
