//
// Created by shira on 1/9/19.
//

#ifndef MILESTONE2_CACHMANAGER_H
#define MILESTONE2_CACHMANAGER_H

template <class Problem, class Solution>
class CacheManager {
public:
    virtual bool hasSolution(Problem problem) = 0;
    virtual Solution getSolution(Problem problem) = 0;
    virtual void saveSolution(Problem problem, Solution solution) = 0;
};

#endif //MILESTONE2_CACHMANAGER_H
