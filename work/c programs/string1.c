#include<stdio.h> 
int main()
{
    char c ;
    for(c = 120; c <= 128; c++)
    {
        sleep(1);
        printf("%d \n",c);
    }
    return 0;
}
