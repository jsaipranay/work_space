#include<stdio.h>
void bubble_sort(int arr[],int n);
void print_array(int arr[],int size);
void swap(int *xp,int *yp);
main()
{

int arr[]={41,85,24,69,94};
int n=sizeof(arr)/sizeof(arr[0]);
bubble_sort(arr,n);
print_array(arr,n);

}
void  bubble_sort(int arr[],int n)
{

int i,j,min_id;
for(i=0;i<n-1;i++)
{
	for(j=0;j<n-i-1;j++)
		if(arr[j]>arr[j+1])
			swap(&arr[j],&arr[j+1]);	


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

}s
