//
// Created by shira on 1/12/19.
//

#include "StringReverser.h"

string StringRecerser::solve(string str) {
    string reversed = string();
    for (int i = str.length() - 1; i >= 0; i--) {
        reversed += str[i];
    }
    return reversed;
}
