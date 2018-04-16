#include<stdio.h>
#include<unistd.h>
main()
{

	int fds[2];
	char buf[30];
	int ret;
	pipe(fds);
	ret=fork();

if(ret>0)
{
	fflush(stdin);
	printf("iam pareent\n");
	write(fds[1],"hellosai",8);

}
if(ret==0)
{
	sleep(1);
	fflush(stdin);
	printf("\n iam child");
	read(fds[0],buf,sizeof(buf));
	write(1,buf,sizeof(buf));



}


return 0;
}

