#include<stdio.h>
#include<signal.h>
#include<unistd.h>
mysighandler(int signal)
{
	printf("handler\n");
	sleep(10);
}

main()
{
	struct sigaction act;
	act.sa_handler=mysighandler;
	act.sa_flags=0;
	sigemptyset(&act.sa_mask);
	
	sigaddset(&act.sa_mask,3);
	sigaction(2,&act,NULL);
	while(1)
	{
		printf("signal\n");
		sleep(5);


	}




}
