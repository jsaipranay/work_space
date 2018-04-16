#include<iostream>
using namespace std;
#include<pthread.h> //Thread,mutex
#include<semaphore.h> //Semaphores

/**********************************************************
Semaphore:Signalling Mechanism
Binary Semaphore: 0,1 states
Counting Semaphore
sem_init(sem_t *s,int pshared,unsigned int value);
NOTE: 
3rd parameter value should always be >=1,cannot be 0
2nd parameter value if 0,thread
                    other than 0,process
**********************************************************/

//Even Odd Threads Implementation
//Thread 1 prints Even no's 2,4,6,8,10
//Thread 2 prints Odd no's 1,3,5,7,9

sem_t s;
//sem_init(&s,0,1); //2nd parameter indicates whether the semaphore is for thread or process
                    //if 0,thread
                    //Non-zero,Process
int x=1; //Global variable,if u want 0 then make x=0

void* evenFunc(void* msg)
{
        sem_wait(&s);
	while(x<=10)
	{
		if(x%2==0)
		{
			cout<<"t1=>Thread id:"<<(int)pthread_self()<<" value:"<<x<<endl;
			x++;
		}
                sem_post(&s);
	}
}

void* oddFunc(void* msg)
{
        sem_wait(&s);
	while(x<=10)
	{
		if(x%2==1)
		{
			cout<<"t2=>Thread id:"<<(int)pthread_self()<<" value:"<<x<<endl;
			x++;
		}
                sem_post(&s);
	}
}

int main()
{
	pthread_t t1,t2;
        sem_init(&s,0,1); //2nd parameter indicates whether the semaphore is for thread or process
                          //3rd parameter enables the semaphore
	pthread_create(&t1,NULL,evenFunc,NULL);//Pass by reference
	pthread_create(&t2,NULL,oddFunc,NULL);
	pthread_join(t1,NULL); //it is pass by value with 2nd Argument
	pthread_join(t2,NULL);
        sem_destroy(&s);
	return 0;
}


