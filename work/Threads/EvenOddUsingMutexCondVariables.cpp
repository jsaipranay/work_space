#include<iostream>
using namespace std;
#include<pthread.h> //Thread,mutex

//Even Odd Threads Implementation
//Thread 1 prints Even no's 2,4,6,8,10
//Thread 2 prints Odd no's 1,3,5,7,9

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
//pthread_cond_t c;
int x=1; //Global variable,if u want 0 then make x=0

void* evenFunc(void* msg)
{
	pthread_mutex_lock(&m);
	while(x<=10)
	{
		if(x%2==0)
		{
//			pthread_cond_wait(&c,&m);
			cout<<"t1=>Thread id:"<<(int)pthread_self()<<" value:"<<x<<endl;
			x++;
		}
		pthread_mutex_unlock(&m);
		//pthread_cond_signal(&c);
	}
//	 pthread_mutex_unlock(&m);
}

void* oddFunc(void* msg)
{
	pthread_mutex_lock(&m);
	while(x<=10)
	{
		if(x%2==1)
		{
//			pthread_cond_wait(&c,&m);
			cout<<"t2=>Thread id:"<<(int)pthread_self()<<" value:"<<x<<endl;
			x++;
		}
		pthread_mutex_unlock(&m);
//		pthread_cond_signal(&c);
	}
//	 pthread_mutex_unlock(&m);
}

int main()
{
	pthread_t t1,t2;
	pthread_create(&t1,NULL,evenFunc,NULL);//Pass by reference
	pthread_create(&t2,NULL,oddFunc,NULL);
	pthread_join(t1,NULL); //it is pass by value with 2nd Argument
	pthread_join(t2,NULL);
	return 0;
}


//Even Odd Threads Implementation
//Thread 1 prints 1,4,7
//Thread 2 prints 2,5,8
//Thread 3 prints 3,6,9

/*
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
int x=1; //Global variable

void* Func1(void* msg)
{
	pthread_mutex_lock(&m);
	while(x<10) //since we dont want 10,we take values lesser than that
	{
		if(x%3==1)
		{
			cout<<"t1=>Thread id:"<<(int)pthread_self()<<" value:"<<x<<endl;
			x++;
		}
		pthread_mutex_unlock(&m);
	}
}

void* Func2(void* msg)
{
	pthread_mutex_lock(&m);
	while(x<10)
	{
		if(x%3==2)
		{
			cout<<"t2=>Thread id:"<<(int)pthread_self()<<" value:"<<x<<endl;
			x++;
		}
		pthread_mutex_unlock(&m);
	}
}

void* Func3(void* msg)
{
	pthread_mutex_lock(&m);
	while(x<10)
	{
		if(x%3==0)
		{
			cout<<"t3=>Thread id:"<<(int)pthread_self()<<" value:"<<x<<endl;
			x++;
		}
		pthread_mutex_unlock(&m);
	}
}

int main()
{
	pthread_t t1,t2,t3;
	pthread_create(&t1,NULL,Func1,NULL);
	pthread_create(&t2,NULL,Func2,NULL);
	pthread_create(&t3,NULL,Func3,NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);
	return 0;
}



void *func(void *msg)
{

char *x = (char*)msg;
cout<<s;
int *x =(int *)msg;
}

int main()
{
pthread_t t1,t2;
pthread_create(&t1,NULL,func,"Hello World");
pthread_create(&t2,NULL,func,'c');
pthread_create(&t3,NULL,func,5);
pthread_create(&t4,NULL,func,12.65);
pthread_join(t1,NULL);
}

*/
