/*

unreated process 
exit in file sytem
open read write
throuh out execution


*/



#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
main()
{

int srvfd,clifd;
char srvbuf[50];
srvfd=open("srvfifo",0642);
if(srvfd>0)
{
	printf("open sucessfully\n");

}
else
{
	if(mkfifo("srvfifo",0642)<0)
	{
		printf("error");
		return;
	}
	
	else
	{
		srvfd=open("srvfifo",0642);
		printf("comes of open");
	}

	if(srvfd<0)
	{
		printf("couldnot open\n");
		exit(0);
	}
}
srvfd=read(srvfd,srvbuf,20);
clifd=open("clififo",O_WRONLY);
printf("%s\n",srvbuf);
if(clifd>0)
{
	printf("opended suucessfully\n");
	
}
write(clifd,srvbuf,srvfd);
printf("sending response");
}








