//
// Created by shira on 1/16/19.
//

#include "MatrixProblem.h"

MatrixProblem::MatrixProblem(vector<vector<int>> &matrix, int startRow, int startColumn, int endRow,
                             int endColumn) {
    this->stateMat = vector<vector<State<pair<int, int>>*>>();
    this->matrix = matrix;
    this->startRow = startRow;
    this->endRow = endRow;
    this->startColumn = startColumn;
    this->endColumn = endColumn;
    for (int i = 0; i < this->matrix.size(); i++) {
        for (int j = 0; j < this->matrix[i].size(); j++) {
            this->stateMat[i][j] = new State<pair<int, int>>(pair<int, int>(i, j), this->matrix[i][j], nullptr, false);
        }
    }
}

vector<vector<int>>* MatrixProblem::getMatrix() {
    return &(this->matrix);
}

int MatrixProblem::getStartRow() {
    return this->startRow;
}

int MatrixProblem::getStartColumn() {
    return this->startColumn;
}

int MatrixProblem::getEndRow() {
    return this->endRow;
}

int MatrixProblem::getEndColumn() {
    return this->endColumn;
}

string MatrixProblem::toString() {
    string describe = string();
    describe += this->matrix.size() + " ";
    for (int i = 0; i < this->matrix.size(); i++) {
        for (int j = 0; j < this->matrix[i].size() - 1; j++) {
            describe += this->matrix[i][j] + ",";
        }
        describe += this->matrix[i][this->matrix[i].size() - 1];
        describe += " ";
    }
    describe += to_string(this->startRow) + "," + to_string(this->startColumn) + " " + to_string(this->endRow) + "," + to_string(this->endColumn);
    return describe;
}

vector<int>* MatrixProblem::separateByComma(string &str) {
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
    result->push_back(stoi(num));
    return result;
}

MatrixProblem* MatrixProblem::generateMatrix(vector<string> &line) {
    vector<vector<int>>* matrix = new vector<vector<int>>();
    for (int i = 0; i < line.size() - STOP; i++) {
        matrix->push_back(*(separateByComma(line[i])));
    }
    int startRow;
    int startColumn;
    int endRow;
    int endColumn;
    vector<int>* start = separateByComma(line[line.size() - STOP]);
    vector<int>* end = separateByComma(line[line.size() - STOP + 1]);
    startRow = (*start)[0];
    startColumn = (*start)[1];
    endRow = (*end)[0];
    endColumn = (*end)[1];
    string numbers = string();
    for (int i = 0; i < line.size(); i++) {
        numbers += line[i];
    }
    numbers = getStringCode(numbers);
    return new MatrixProblem(*matrix, startRow, startColumn, endRow, endColumn);
}

string MatrixProblem::getStringCode(string &str) {
    string result = to_string(hash<string>{}(str));
    return result;
}

MatrixProblem MatrixProblem::fromString(string &str) {
    string cleanLine = string();
    vector<string> lines = vector<string>();
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            cleanLine += str[i];
        }
        else {
            lines.push_back(cleanLine);
            cleanLine = string();
        }
    }
    lines.push_back(cleanLine);
    return *(generateMatrix(lines));
}

State<pair<int, int>>* MatrixProblem::getInitialState() {
    return this->stateMat[this->startRow][this->startColumn];
}

State<pair<int, int>>* MatrixProblem::getGoalState() {
    return this->stateMat[this->endRow][this->endColumn];
}

vector<State<pair<int, int>>*> MatrixProblem::getAllPossibleStates(State<pair<int, int>>* s) {
    vector<State<pair<int, int>>*> neighbors = vector<State<pair<int, int>>*>();
    pair<int, int> val = s->getValue();
    if (val.first > 0) {
        neighbors.push_back(this->stateMat[val.first - 1][val.second]);
    }
    if (val.second > 0) {
        neighbors.push_back(this->stateMat[val.first][val.second - 1]);
    }
    if (val.first < this->stateMat.size() - 1) {
        neighbors.push_back(this->stateMat[val.first + 1][val.second]);
    }
    if (val.second < this->stateMat[val.first].size() - 1) {
        neighbors.push_back(this->stateMat[val.first][val.second + 1]);
    }
    return neighbors;
}


