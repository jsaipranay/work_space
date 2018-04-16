
	#include <sys/wait.h>
       #include <stdio.h>
       #include <stdlib.h>
       #include <unistd.h>
       #include <string.h>
main()
{	
	char buf[30];
	int id;
	int fds[2];
	pipe(fds);
	id=fork();
	if(id==0)
	{
		close(fds[0]);
		read(fds[1],buf,20);
		printf("%s",buf);
	
	}
	else
	{

		close(fds[1]);
		scanf("%s",buf);
		write(fds[0],20,strlen(buf));
	}
}
