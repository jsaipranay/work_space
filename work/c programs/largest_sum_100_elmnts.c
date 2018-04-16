#include<stdio.h> 
int main(void)
{
    int a[10] = {-1,-30,-3,-4,5,6,-7,8,-9,1};
    int i,j;
    int temp,lar_sum=0;
    for(i = 0; i < 9; i++)
    {
        temp = a[i] + a[i+1] ;

        if ( temp  >  lar_sum )
        {
            lar_sum = temp;
        }
    }
    printf("%d\n",lar_sum);
    return 0;
}
