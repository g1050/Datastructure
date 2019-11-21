#ifndef CAL_H
#define CAL_H

#include <string>
#include <vector>
#include "../stack.hpp"
#include <cmath>
#include <QString>

class cal
{
public:
    cal(std::string s) {
        this->s = s;
    }
    ~cal() {}
    bool ifLegal();
    void toPostfix();
    int getPriority(char c);
    double getValue();
private:
    std::string s;
    std::vector <char> v;
};
#endif // CAL_H




