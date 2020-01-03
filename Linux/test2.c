#include <stdio.h>

int main()
{
    
    int a[6] = {0x6f796958, 0x694c2075, 0x2078756e,0x756f7247, 0x30322070, 0};
    char *p = (char*)a;
    for(;*p != '\0';p++){
        printf("%c",*p);
    }

    printf("\n");
    printf("%d\n",printf("%s",(void *)a));
    return 0;
}

