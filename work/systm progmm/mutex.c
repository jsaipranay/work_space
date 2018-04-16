/*for sequential executon of instructions 

thread has thred id in kernel space,
thraed has entry point.


clone is a system call use for cretae thread but argumnts of thresd are diff so we go with pthread _create.

#include <stdio.h> 
#include<pthread.h> 
void threadfun(void *args);
main()
{
int res;

pthread_t tid;
pthread_create(&tid,NULL,threadfun,"helloworld");
pthread_join(tid,&res);
printf("%s",res);
}
void threadfun(void *args)
{
	
	char *ptr;
	ptr=((char *)args);
	

}*/







	#include <stdio.h>
 	#include <pthread.h>
       #include <string.h>
       
       #include <stdlib.h>
       #include <unistd.h>
       #include <errno.h>
       #include <ctype.h>
void main(void);
void main(void)
{
     int num = 100;
     char str[25];
     itoa(num, str, 10);
     printf("The number 'num' is %d and the string 'str' is %s.\n",
                 num, str);
}

pthread_mutex_t mtx;

void threadfun1(void *args);
void threadfun2(void *args);
int glob=0;
main()
{
int res;
int loop=1000;
pthread_t tid1,tid2;
pthread_create(&tid1,NULL,threadfun1,&loop);
pthread_create(&tid2,NULL,threadfun2,&loop);
pthread_create(&tid1,NULL,threadfun1,&loop);
pthread_create(&tid2,NULL,threadfun2,&loop);
pthread_join(tid1,&res);
pthread_join(tid2,&res);
pthread_join(tid1,&res);
pthread_join(tid2,&res);
printf("%d",glob);
}

void threadfun1(void *args)
{
	int i,loop,loc;
	loop=(*(int *)args);
	pthread_mutex_lock(&mtx);
	for(i=0;i<loop;i++)
	{

		loc=glob;
		loc++;
		glob=loc;

	}
pthread_mutex_unlock(&mtx);
}

void threadfun2(void *args)
{
	int i,loop,loc;
	loop=(*(int *)args);
	pthread_mutex_lock(&mtx);
		
	for(i=0;i<loop;i++)
	{

		loc=glob;
		loc++;
		glob=loc;

	}
	pthread_mutex_unlock(&mtx);
	
}


/*mutex are syancronisation purpose,
when mul process acess the same critical section mutex locks come in pcture

mutex intitailly in state unlock mode,and counter 1
			lock to     counter 0;
                    */
