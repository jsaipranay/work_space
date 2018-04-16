#include<stdio.h>
void insertion_Sort(int arr[], int n);
void print_array(int arr[],int size);
void swap(int *xp,int *yp);
main()
{

int arr[]={41,85,24,69,94};
int n=sizeof(arr)/sizeof(arr[0]);
insertion_Sort(arr,n);
print_array(arr,n);

}
void insertion_Sort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
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
