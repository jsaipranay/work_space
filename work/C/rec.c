#include<stdio.h>
fact(int a);
main()
{

	int f;
	f=fact(5);
	printf("%d\n",f);


}
fact (int a)
{

	int f;	
	if(a==1)
		return 1;
	printf("%d\n",a);
	f=a*fact(a-1);
	return f;


}


