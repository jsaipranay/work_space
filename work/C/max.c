#include<stdio.h>
main()
{

int i,arr[5]={2,4,5,6,9};
int max,min=arr[0];
for(i=0;i<5;i++)
{
	if(arr[i]<min)
		min=arr[i];
	if(arr[i]>max)
		max=arr[i];


}
printf("%d.%d",min,max);


}
