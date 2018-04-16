#include<stdio.h>
main()
{
	int i,j,t;
	int arr[10]={21,20,1,9,4,7,8,9,10,11};
	for(i=0,j=9;i<j;i++,j--)
	{
		t=arr[i];
		arr[i]=arr[j];
		arr[j]=t;
		


	}

for(i=0;i<10;i++)
	printf("%d\t",arr[i]);



}
