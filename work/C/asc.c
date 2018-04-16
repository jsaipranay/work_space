#include<stdio.h>
main()
{

	int i,j,t;
	char arr[10];
	for(i=0;i<10;i++)
	scanf("%d",&arr[i]);
	for(i=0;i<9;i++)
	{
		for(j=i+1;j<10;j++)
		{
			if(arr[i]>arr[j])
			{
				t=arr[i];
				arr[i]=arr[j];
				arr[j]=t;


			}
			
		}



	}


for(j=0;j<10;j++)
printf("%d\t",arr[j]);

}
