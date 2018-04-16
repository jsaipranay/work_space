#include<stdio.h>

int table(int i,int n)
{
    int x;
    if(i==11){
        return 0;
    }
    else{
        x=n*i;
        printf(" %d * %d = %d\n",n,i,x);
        return (table(++i,n));
    }
}

int main()
{
    int n;
    printf("Enter number to get table ");
    scanf("%d",&n);

    /*****************************/
    table(1,n);
    /*****************************/

    return 0;
}
