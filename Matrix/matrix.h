#ifndef __MATRIX__H_
#define __MATRIX__H_

#define MAXSIZE 1000
#include <iostream>
struct Triple
{
    int row,col;
    int value;
};

struct TSMATRIX
{
    Triple data[MAXSIZE+1];
    int row,col,nums;
};

class Matrix
{
public:
    void printMenu();
    void plus();
    void sub();
    void mul();
    void reverse();
private:
    void inputMatrix(TSMATRIX &in);
    void PrintMatrix(TSMATRIX &ma);
    int findElement(TSMATRIX &in,int row,int col);
    TSMATRIX m1,m2,res;    
};

#endif
