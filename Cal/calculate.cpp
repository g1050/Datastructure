#include <iostream>
#include "exp.hpp"
int main()
{
    string s;
    cin >> s;
    Exp exp(s);
    if(exp.ifLegal())  cout << "Legal!\n";
    else cout << "Unlegal!\n";
    exp.toPostfix();
    cout << "res = " << exp.getValue();
    return 0;
}

