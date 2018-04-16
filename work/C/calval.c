#include<stdio.h>
int val(int *x,int *y);
main()
{

	int a=5,b=8;
	val(&a,&b);
printf("%d......%d\t",a,b);

}
int val(int *x,int *y)
{
	(*x)++;
	(*y)++;
printf("%d....%d\t",*x,*y);

}
