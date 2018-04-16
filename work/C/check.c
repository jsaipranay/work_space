#include<stdio.h>
void check(int num[]);
main()
{

int i,arr[5]={1,2,3,4,5};
check(arr);
for(i=0;i<5;i++)
{
	printf("%d\t",arr[i]);

}
}
void check(int num[])
{
int i;
for(i=0;i<5;i++)
{

num[i]*=num[i];

}
}
