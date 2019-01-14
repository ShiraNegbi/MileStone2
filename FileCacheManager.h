//
// Created by shira on 1/9/19.
//

#ifndef MILESTONE2_FILECACHEMANAGER_H
#define MILESTONE2_FILECACHEMANAGER_H
#include <string>
#include <unordered_map>
#include <fstream>
#include <sstream>
#include "CacheManager.h"
using namespace std;

template <class Problem, class Solution>
class FileCacheManager : public CacheManager {
    string fileName;
    unordered_map<Problem, Solution> solved;
    void loadFromFile();
public:
    FileCacheManager(string fileName);
    virtual bool hasSolution(Problem problem);
    virtual Solution getSolution(Problem problem);
    virtual void saveSolution(Problem problem, Solution solution);
};

#endif //MILESTONE2_FILECACHEMANAGER_H
