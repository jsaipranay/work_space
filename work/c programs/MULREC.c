#include<stdio.h> 

int muli(int n1,int n2)
{

    if(n2 == 1)
        return n1;
    else
    {

        return n1+muli(n1,(n2-1));
    }
}

int main(void)
{

    int n1 =10;
    int n2 =20;

    int mul =  muli(n1,n2 );
    printf("mul = %d\n",mul);
    return 0;
}
