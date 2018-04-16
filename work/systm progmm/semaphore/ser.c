#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/sem.h>

#define KEY 192112
void togglecase(char *addr);
main()
{
	int semid,shmid;
	struct sembuf *smop;
	
	char *addr;
	shmid=shmget(KEY,512,IPC_CREAT|0660);
	addr=shmat(shmid,NULL,0);
	semid=semget(KEY,1,IPC_CREAT|0660);
	semctl(semid,0,SETVAL,0);
	semctl(semid,1,SETVAL,0);
	smop[0].sem_num=0;
	smop[0].sem_op=-1;
	//smop[0].sem_flags=0;
	semop(semid,&smop,1);
	printf("%s",addr);
	togglecase(addr+256);
	smop[1].sem_num=1;
	smop[1].sem_op=1;
	//[1].sem_flag=0;
	semop(semid,&smop,1);

}
void togglecase(char *addr)
{

	int i;
	for(i=0;i<strlen(addr);i++)
	{
		if(isupper(addr[i]))
			addr[i]=tolower(addr[i]);
		else
		addr[i]=toupper(addr[i]);


	}


}
