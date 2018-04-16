#include<stdio.h>
#include<string.h>

char non_rep(char *str);
main()
{

	char str[20]="abcdabc";
	printf("%c",non_rep(str));
}
char non_rep(char *str)
{
	int len,i,j,repeated=0;
	len=strlen(str);
	for(i=0;i<len;i++)
	{
		repeated=0;
		for(j=0;j<len;j++)
		{
			if(i!=j && str[i]==str[j])
			{	
				repeated=1;
				break;
			}
		}
		if(repeated==0)
			return str[i];
	}	
	return ' ';
}
