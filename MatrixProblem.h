//
// Created by shira on 1/16/19.
//

#ifndef MILESTONE2_MATRIXPROBLEM_H
#define MILESTONE2_MATRIXPROBLEM_H
#include <string>
#include <vector>
#define STOP 2
using namespace std;

class MatrixProblem {
private:
    vector<vector<int>> matrix;
    int startRow;
    int startColumn;
    int endRow;
    int endColumn;
    static vector<int>* separateByComma(string &str);
public:
    MatrixProblem(vector<vector<int>> &matrix, int startRow, int startColumn, int endRow,
                  int endColumn);
    static MatrixProblem fromString(string &str);
    vector<vector<int>>* getMatrix();
    int getStartRow();
    int getStartColumn();
    int getEndRow();
    int getEndColumn();
    string toString();
    static MatrixProblem* generateMatrix(vector<string> &line);
    static string getStringCode(string &str);
};

#endif //MILESTONE2_MATRIXPROBLEM_H
