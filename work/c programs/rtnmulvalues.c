#include<stdio.h> 
typedef struct st
{
    int x;
    int y;
}ST;
ST fun1() 
{
    ST *result;
    result->x = 10;
    result->y = 20;
    return result;
}


int main(void)
{
    ST res;
    res = fun1();

    printf("%d\n",res.x);
    printf("%d\n",res.y);
    return 0;
}
