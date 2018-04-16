#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
main()
{
int srvfd;
int clifd;
char srvbuf[50];
srvfd=open("srvfifo",O_WRONLY);
printf("entrer string\n");
scanf("%s",srvbuf);
write(srvfd,srvbuf,strlen(srvbuf));
clifd=open("clififo",O_RDONLY);
if(clifd>0)
{

	printf("open succesfully\n");

}
else
{

	if(mkfifo("clififo",0642)<0)
	{
		printf("error\n");
		return;
	}

srvfd=open("clififo",O_RDONLY);
}	

read(clifd,srvbuf,20);
printf("%s\n",srvbuf);
printf("response of serer\n");
}



