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
	

}




 

