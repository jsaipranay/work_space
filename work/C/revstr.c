#include<stdio.h>
#include<string.h>
main()
{

int len;
char str[20];
scanf("%[^\n]",str);
for(len=strlen(str)-1;len>=0;len--)
{
	printf("%c",str[len]);

}



}
