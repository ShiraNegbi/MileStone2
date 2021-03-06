//
// Created by shira on 1/14/19.
//

#ifndef MILESTONE2_MYCLIENTHANDLER_H
#define MILESTONE2_MYCLIENTHANDLER_H

#include "ClientHandler.h"
#include "CacheManager.h"
#include "Solver.h"
#include "MatrixProblem.h"
#include <string>
#include <sstream>
#include <unistd.h>
#include <strings.h>
#include <vector>

#define BUFFER_SIZE 1024
using namespace std;

template<class Problem, class Solution>
class MyClientHandler : public ClientHandler {

    Solver<Problem, Solution>* solver;
    CacheManager* cacheManager;

    //a converter that converts from problem to a string and vice versa
    Decoder<Problem>* problemDecoder;
    //a converter that converts from solution to a string and vice versa
    Decoder<Solution>* solutionDecoder;

public:
    MyClientHandler(Solver<Problem, Solution>* solver, CacheManager* cacheManager){
        this->solver = solver;
        this->cacheManager = cacheManager;
    }

    virtual void handleClient(int input, int output) override{
/**
הלקוח שולח שורה אחר שורה עד שמתקבלת שורה עם הערך
“end”
כל שורה מחילה ערכים מספריים המופרדים ע"י פס
יק. כך אוסף השורות יוצר מטריצה של
ערכים.
לאחר מכן הלקוח שולח שתי שורות נוספות. בכל שורה שני ערכים המופרדים ע"י פסיק: שורה
ועמודה.
Row,Col
הערכים בשורה הראשונה מציינים את הכניסה לשטח
הערכים בשורה השנייה מציינים את היציאה מהשטח

כעת השרת יחזיר מחרוזת אחת בלבד
, עם ערכים המופרדים בפסיק. הערכים יהיו מסוג המילים
{
Up,  Down,  Left,  Right
} שמציינות את הכיוון שיש לנוע לפיו על מנת לחצות את השטח
במסלול הזול ביותר
 */
        bool isOver = false;
        string line;
        char buff[BUFFER_SIZE];;
        int len;
        vector<string> inputLines = vector<string>();
        while (!isOver) {
            bzero(buff, BUFFER_SIZE);
            len = (int) read(input, buff, BUFFER_SIZE - 1);
            line = buff;
            if (len < 0) {
                perror("Cannot read from socket");
                exit(1);
            }
            if (line == "end" || line == "end\n" || line == "end\r\n") {
                isOver = true;
            } else {
                inputLines.push_back(line);
            }
        }
        MatrixProblem problem = *(problem.generateMatrix(inputLines));
        Solution solution;
        if (this->cacheManager->hasSolution(problem.toString())) {
            solution = this->cacheManager->getSolution(problem.toString());
        } else {
            solution = solver->solveProblem(problem);
            this->cacheManager->saveSolution(problem.toString(), solution);
        }
        string solutionString = this->solver.solve(problem).toString();
        len = write(input, solutionString.c_str(), (int) (solutionString.length()));
        if (len < 0) {
            perror("Cannot write to socket");
            exit(1);
        }
        //close(input);
    }
};


#endif //MILESTONE2_MYCLIENTHANDLER_H
