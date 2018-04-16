#include<stdio.h> 
int main(void)
{
    int a[10] = {1,30,3,4,50,6,7,8,9,10};
    int i,j;
    int temp,lar=0;
    for(i = 0; i < 10; i++)
    {
        temp = a[i] - lar;
        lar = ((temp >> 31 & 1) ? ( lar ) : ( a[i] ));
    }
    printf("%d\n",lar);
    return 0;
}

