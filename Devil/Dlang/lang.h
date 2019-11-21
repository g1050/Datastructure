#ifndef LANG_H
#define LANG_H
#include <iostream>
#include "../../Cal/queue.hpp"
#include "../../Cal/stack.hpp"

class Lang
{

public:
    Lang(){
        res = "";
    }

    void setString(string s){
        this->s = s;
    }

    bool ifLegal();
    string toNormal();
private:
    string s;
    string res;
    stack <char> s1;
    stack <char> s2;
    queue <char> q;
};

#endif // LANG_H
