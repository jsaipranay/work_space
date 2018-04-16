#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/msg.h>
#define SRV_MSG_TYPE 1
#define KEY	199250
main()
{
int msgid;
char rxmsg[20],txmsg[20];
msgid=msgget(KEY,0642|IPC_CREAT);
if(msgid<0)
{

printf("no msgqueue\n");
return 1;
}
else
{

printf("opened msgqueue %d\n",msgid);
}
msgrcv(msgid,rxmsg,20,SRV_MSG_TYPE,NULL);
memcpy(txmsg,rxmsg+4,4+strlen(txmsg+4)+1);
msgsnd(msgid,txmsg,4+strlen(txmsg+4)+1,NULL);

}
