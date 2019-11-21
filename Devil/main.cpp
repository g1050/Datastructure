#include <iostream>
#include <string>
#include "Lang.hpp"
using namespace std;

int main()
{
    string s;
    cin >> s;
    Lang l;
    l.setString(s);
    if(l.ifLegal()){
        cout << "Leagal" << endl;
        cout << l.toNormal() << endl;
    }else{
        cout << "string is illegal" << endl;
    }
    return 0;
}

