#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <sys/sem.h>

#define KEY 192112
main()
{
	int semid,shmid;
	struct sembuf *smop;
	char *addr;
	shmid=shmget(KEY,512,0);
	addr=shmat(shmid,NULL,0);
	semid=semget(KEY,2,0);
	scanf("%s",addr);
	
	smop[0].sem_num=0;
	smop[0].sem_op=+1;
	//[0].sem_flags=1;
	semop(semid,&smop[0],1);
	smop[1].sem_num=1;
	smop[1].sem_op=-1;
	//smop[1].sem_flag=1;
	semop(semid,&smop,1);
	printf("%s",addr+256);
}




