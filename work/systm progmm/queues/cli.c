#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
main()
{
	int srvfd,clifd,rd;
	char srvbuf[20];
	srvfd=open("srvfifo",O_WRONLY);
	scanf("%s",srvbuf);
	write(srvfd,srvbuf,strlen(srvbuf));
	clifd=open("clififo",O_RDONLY);
	if(clifd>0)
	{
		printf("opened succesfully\n");
		
	}
	else
	{
		if(mkfifo("clififo",0642)<0)
		{
			printf("error\n");
			return;		
		}
		else
		{
			clifd=open("clififo",O_RDONLY);
			printf("comes out of open\n");



		}
	}	
	read(srvfd,srvbuf,20);
	printf("responded\n");
}
