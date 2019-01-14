//
// Created by shira on 1/14/19.
//

#include "MatrixHandler.h"

MatrixHandler::MatrixHandler() {}

vector<vector<int>>* MatrixHandler::generateMatrix(vector<string> &line) {
    vector<vector<int>>* matrix = new vector<vector<int>>();
    for (int i = 0; i < line.size() - STOP; i++) {
        matrix->push_back(*(this->separateByComma(line[i])));
    }
    return matrix;
}

vector<int>* MatrixHandler::separateByComma(string &str) {
    string num = string();
    vector<int>* result = new vector<int>();
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ',') {
            result->push_back(stoi(num));
            num = string();
        }
        else {
            if (str[i] >= '0' && str[i] <= '9') {
                num += str[i];
            }
        }
    }
    return result;
}
