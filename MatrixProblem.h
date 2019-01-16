//
// Created by shira on 1/16/19.
//

#ifndef MILESTONE2_MATRIXPROBLEM_H
#define MILESTONE2_MATRIXPROBLEM_H
#include <string>
#include <vector>
#include "Searchable.h"
#define STOP 2
using namespace std;

class MatrixProblem : public Searchable<pair<int, int>> {
private:
    vector<vector<State<pair<int, int>>*>> stateMat;
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

    State<pair<int, int>>* getInitialState() override;

    State<pair<int, int>>* getGoalState() override;

    vector<State<pair<int, int>>*> getAllPossibleStates(State<pair<int, int>>* s) override;
};

#endif //MILESTONE2_MATRIXPROBLEM_H
