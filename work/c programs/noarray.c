#include<stdio.h> 
int main(void)
{

    static int i =0;

    if(i<2)
    {
        i++;
        printf("%p\n", main());
    }
}
