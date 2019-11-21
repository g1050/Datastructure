#include <iostream>
#include "File.h"
#include <map>
using namespace std;
int main(int argc,char *argv[])
{
    if(argc != 3){
        cout << "[usage]:xuzip source destination" << endl;;
        return 0;
    }


    /* File file; */
    /* file.encoded(argv[1],argv[2]); */  
    /* file.getVector(); */

    File file2;
    file2.decoding(argv[1],argv[2]);

    return 0;
}

