#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
main()
{
	int srvfd,clifd,rd;
	char srvbuf[20];
	srvfd=open("srvfifo",O_RDONLY);
	if(srvfd>0)
	{
		printf("opened succesfully\n");
		
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
			srvfd=open("srvfifo",O_RDONLY);
			printf("comes out of open\n");



		}
	
	
	}
	rd=read(srvfd,srvbuf,20);
	clifd=open("clififo",O_WRONLY);
	if(clifd>0)
	{

		printf("ope succesfully\n");
		
	}
	write(clifd,srvbuf,rd);
	printf("send response\n%s\n",srvbuf);;
		






}

