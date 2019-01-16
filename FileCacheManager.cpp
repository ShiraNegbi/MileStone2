//
// Created by shira on 1/9/19.
//

#include "FileCacheManager.h"

template<class Problem, class Solution>
void FileCacheManager<Problem, Solution>::loadFromFile() {
    //load the solutions to the map
    ifstream stream;
    stream.open(this->fileName);
    if (!stream.good()) {
        return;
    }
    string problemString;
    string solutionString;
    Problem problem;
    Solution solution;
    while (getline(stream, problemString)) {
        getline(stream, solutionString);
        problem = problem.fromString(&problemString);
        solution = solution.fromString(&solutionString);
        this->solved[problem] = solution;
    }
    stream.close();
    return;
}

template<class Problem, class Solution>
FileCacheManager<Problem, Solution>::FileCacheManager(string fileName) {
    this->fileName = fileName;
    this->solved = unordered_map<Problem, Solution>();
    loadFromFile();
}

template<class Problem, class Solution>
bool FileCacheManager<Problem, Solution>::hasSolution(Problem problem) {
    return this->solved.find(problem) > 0;
}

template<class Problem, class Solution>
Solution FileCacheManager<Problem, Solution>::getSolution(Problem problem) {
    if (this->hasSolution(problem)) {
        return this->solved[problem];
    }
    return NULL;
}

template<class Problem, class Solution>
void FileCacheManager<Problem, Solution>::saveSolution(Problem problem, Solution solution) {
    this->solved[problem] = solution;
    // write in the file
    ofstream stream;
    stream.open(this->fileName, ios_base::app);
    stream << problem.toString()  << endl;
    stream << solution.toString() << endl;
    stream.close();
}
