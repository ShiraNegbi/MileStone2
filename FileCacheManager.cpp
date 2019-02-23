//
// Created by shira on 1/9/19.
//

#include <iostream>
#include "FileCacheManager.h"

FileCacheManager::FileCacheManager(string fileName) {
    this->fileName = fileName;
    this->solved = unordered_map<string, string>();
    loadFromFile();
}

void FileCacheManager::loadFromFile() {
    //load the solutions to the map
    ifstream stream;
    stream.open(this->fileName);
    if (!stream.good()) {
        return;
    }

    string problem;
    string solution;
    while (getline(stream, problem)) {
        try {
            getline(stream, solution);
        } catch (exception &e) {
            std::cerr << "Error in reading file: probably missing solution for a problem" << std::endl;
            std::cerr << e.what();
        }
        this->solved[problem] = solution;
    }
    stream.close();
}

bool FileCacheManager::hasSolution(string problem) {
    return this->solved.find(problem) != solved.end();
}

string FileCacheManager::getSolution(string problem) {
    if (this->hasSolution(problem)) {
        return this->solved[problem];
    }
    return NULL;
}

void FileCacheManager::saveSolution(string problem, string solution) {
    this->solved[problem] = solution;
    // write in the file
    ofstream stream;
    stream.open(this->fileName, ios_base::app);
    stream << problem << endl;
    stream << solution << endl;
    stream.close();
}
