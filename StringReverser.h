//
// Created by shira on 1/12/19.
//

#ifndef MILESTONE2_STRINGREVERSER_H
#define MILESTONE2_STRINGREVERSER_H
#include <string>
#include "Solver.h"
using namespace std;

class StringRecerser : public Solver<string, string> {
    string solve(string str) override;
};

#endif //MILESTONE2_STRINGREVERSER_H
