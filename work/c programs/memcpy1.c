#include<stdio.h> 

int main(void)
{

    int a = 12;
    char b[10];

    memcpy(b,(int*)a,4);

    printf("%s\n",b);
    return 0;
}


