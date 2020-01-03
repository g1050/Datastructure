#include <stdio.h>

int i ;
int main()
{
    i--;
    if(i > sizeof(i)){
        printf(">\n");
    }else{
        printf("<\n");
    }
    printf("%u\n",i);
    return 0;
}

