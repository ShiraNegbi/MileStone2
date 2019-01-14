//
// Created by shira on 1/14/19.
//

#ifndef MILESTONE2_MATRIXHANDLER_H
#define MILESTONE2_MATRIXHANDLER_H
#include <vector>
#include <string>
#define STOP 2
using namespace std;

class MatrixHandler {
    vector<int>* separateByComma(string &str);
public:
    MatrixHandler();
    vector<vector<int>>* generateMatrix(vector<string> &line);
};

#endif //MILESTONE2_MATRIXHANDLER_H
