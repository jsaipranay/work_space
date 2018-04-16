#include<stdio.h>
main()
{
	int prime,up,low,i,n;
	scanf("%d",&low);
	scanf("%d",&up);
	for(n=low+1;n<up;n++)
	{
		prime=1;
		for(i=2;i<n/2;i++)
			if(n%i==0)
			{
				prime=0;
				break;

			}

		if(prime)
			printf("%d\t",n);

	}


}
