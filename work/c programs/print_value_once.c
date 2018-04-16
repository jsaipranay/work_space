/***     remove the duplicate array elements ***/               
#include<stdio.h> 
/*
int main(void)
{
    int a[15] = {1,2,3,9,1,2,4,5,3,4,5,2,5,5,5};
    int i,j,k;
    int num = 15;
    int temp[10]; 
    for(i = 0; i <= num; i++)
    {
        for(j= i+1;j<num;j++)
        {
            if(a[i] == a[j])
            {
                for(k = j; k < num ;k++ )
                    a[k] = a[k+1];
                num--;
                i--;
            }
        }
    }
    for(i = 0 ; i < num; i++ )
    {
        printf("%d ",a[i]);
    }
    return 0;
}



void duplicate(int array[], int num)
{
    int *count = (int *)malloc(100);
    int i;
    printf("duplicate elements present in the given array are ");
    for (i = 0; i < num; i++)
    {
        if (count[array[i]] == 1)
            printf(" %d ", array[i]);
        else
            count[array[i]]++;
    }
}
int main()
{
    int array[] = {5, 10, 10, 2, 1, 4, 2};
    int array_freq = sizeof(array) / sizeof(array[0]);
    duplicate(array, array_freq);
    return 0;
}
*/



int main(void)
{
    int a[] = {1,2,3,2,3,4,5,4,3,2,3,4,5};
    int n = sizeof(a) / sizeof(a[0]);
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(a[i] == a[j])
                break;
        }
        if(i==j)
        {
            printf("%d ",a[i]);
        }
    }
    return 0;
}
















