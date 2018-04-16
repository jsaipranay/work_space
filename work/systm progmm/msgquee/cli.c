#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/msg.h>
#define SRV_MSG_TYPE 1
#define KEY	199250
main()
{

int msgid,*msghdr;
char rxmsg[20],txmsg[20];
msgid=msgget(KEY,0);
msgsnd(msgid,txmsg,8+strlen(txmsg+8),NULL);;
msghdr[0]=SRV_MSG_TYPE;
msghdr[1]=getpid();
scanf("%s",txmsg);
msgsnd(msgid,txmsg,8+strlen(txmsg+8),NULL);
msgrcv(msgid,rxmsg,20,getpid,NULL);
printf("%s",rxmsg+4);




}
