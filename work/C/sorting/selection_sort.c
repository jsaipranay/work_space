#include<stdio.h>
void sort_array(int arr[],int n);
void print_array(int arr[],int size);
void swap(int *xp,int *yp);
main()
{

int arr[]={41,85,24,69,94};
int n=sizeof(arr)/sizeof(arr[0]);
sort_array(arr,n);
print_array(arr,n);

}
void  sort_array(int arr[],int n)
{

int i,j,min_id;
for(i=0;i<n-1;i++)
{
	min_id=i;
	for(j=i+1;j<n;j++)
	if(arr[j]<arr[min_id])
		min_id=j;	

swap(&arr[min_id],&arr[i]);
}
}
void swap(int *xp,int *yp)
	{
		int temp=*xp;
		*xp=*yp;
		*yp=temp;

	}
void print_array(int arr[],int size)
{
int i;
for(i=0;i<size;i++)
	printf("%d\t",arr[i]);

}
