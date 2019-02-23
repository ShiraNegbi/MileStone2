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

class FileCacheManager : public CacheManager {
private:
    string fileName;
    unordered_map<string, string> solved;

    void loadFromFile();

public:
    explicit FileCacheManager(string fileName);

    virtual bool hasSolution(string problem) override;

    virtual string getSolution(string problem) override;

    virtual void saveSolution(string problem, string solution) override;
};

#endif //MILESTONE2_FILECACHEMANAGER_H
