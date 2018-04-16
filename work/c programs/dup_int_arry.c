#include<stdio.h>
int dup(int *a,int num)
{
    int i=0,j=0;
    int buf[255] = {0};
    int temp;
    while(i < num)
    {
        temp = a[i] ;

        if(buf[temp] == 0)
        {
            buf[temp] =1;
            a[j] = a[i];
                j++;
        }
        i++;
    }

    return j;
}

int main(void)
{
    int a[10] = {1,1,1,1,2,1,2};
    int res = dup(a,10);
    int i;
    for(i=0; i < res-1 ;i++)
    {
        printf("%d ",a[i]);
    }
    return 0;
}
