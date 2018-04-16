#include<stdio.h>
#include<string.h>
main()
{
	char str[20];
	int i,j;
	scanf("%s",str);
	for(i=0,j=strlen(str)-1;i<=j;i++,j--)
	{
		if(str[i]!=str[j])
			break;
	}
if(i>j)
	printf("pall");
else
	printf("not");


}
