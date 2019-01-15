//
// Created by shira on 1/9/19.
//

#include "MyTestClientHandler.h"

template<class Problem, class Solution>
MyTestClientHandler<Problem, Solution>::MyTestClientHandler(Solver<Problem, Solution>* solver,
                                                            CacheManager<Problem, Solution>* cacheManager) {
    this->solver = solver;
    this->cacheManager = cacheManager;
}

template<class Problem, class Solution>
void MyTestClientHandler<Problem, Solution>::handleClient(int input, int output) {
    bool isOver = false;
    string line;
    char buff[BUFFER_SIZE];
    int len;
    while (!isOver) {
        bzero(buff, BUFFER_SIZE);
        len = (int)read(input, buff, BUFFER_SIZE - 1);
        line = buff;
        if (len < 0) {
            perror("Cannot read from socket");
            exit(1);
        }
        if (line == "end" || line == "end\n" || line == "end\r\n") {
            isOver = true;
        } else {
            Problem problem = (Problem) line;
            Solution solution;
            if (cacheManager->hasSolution(problem)) {
                solution = cacheManager->getSolution(problem);
            } else {
                solution = solver->solveProblem(problem);
                cacheManager->saveSolution(problem, solution);
            }
            string solutionString = solution.toString();
            len = write(input, solutionString.c_str(), (int)(solutionString.length()));
            if (len < 0) {
                perror("Cannot write to socket");
                exit(1);
            }
        }
    }
    //close(input);
}
