#ifndef MODEL_H
#define MODEL_H

#include <QString>

class model
{
public:
    model();
    void setNum1(int num);
    void setNUm2(int num);
    void setFlag(QString flag);
    QString doExpr();
private:
    int num1;
    int num2;
    QString flag;
    int result;

};

#endif // MODEL_H
