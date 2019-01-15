//
// Created by shira on 1/14/19.
//

#include "MyClientHandler.h"

template<class Problem, class Solution>
MyClientHandler<Problem, Solution>::MyClientHandler(Solver<Problem, Solution>* solver) {
    this->solver = solver;
    this->matrixHandler = MatrixHandler();
}

template<class Problem, class Solution>
void MyClientHandler<Problem, Solution>::handleClient(int input, int output) {
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
    char buff[BUFFER_SIZE];
    int len;
    vector<string> inputLines = vector<string>();
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
            inputLines.push_back(line);
        }
    }
    string solutionString = this->solver.solve(*(this->matrixHandler.generateMatrix(inputLines)));
    len = write(input, solutionString.c_str(), (int)(solutionString.length()));
    if (len < 0) {
        perror("Cannot write to socket");
        exit(1);
    }
    //close(input);
}
