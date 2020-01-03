#include <stdio.h>

int main()
{
    int a = 1;
    printf("%d\n",*(char *)&a);
    return 0;
}

