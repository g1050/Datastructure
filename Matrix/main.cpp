#include "matrix.h"
using namespace std;
int main()
{
    Matrix M;
    int choice;

    do{
        M.printMenu();
        cout << "请输入你要进行的操作";
        cin >> choice ;
        switch(choice)
        {
        case 1:
            M.plus();
            break;
        case 2:
            M.sub();
            break;
        case 3:
            M.mul();
            break;
        case 4:
            M.reverse();
            break;
        case 0:
            break;
        default:
            cout << "请输入正确选项!" << endl;
            break;
        }
    }while(choice != 0);
    return 0;

}

