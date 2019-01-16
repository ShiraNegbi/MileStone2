#include <iostream>
#include <string>
#include "MatrixHandler.h"
using namespace std;

int main() {
    MatrixHandler matHandler = MatrixHandler();
    vector<string> lines = vector<string>();
    string numbers = string();
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            numbers += to_string(j) + ", ";
        }
        numbers += "3";
        lines.push_back(numbers);
        numbers = string();
    }
    lines.push_back("0,0");
    lines.push_back("3,3");
    vector<vector<int>> result = *matHandler.generateMatrix(lines);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << to_string(result[i][j]) + " ";
        }
        cout << endl;
    }
    return 0;
}