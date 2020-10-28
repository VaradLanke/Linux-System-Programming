/*
	Program which performs interprocess communication 
	using the concept of message queue.(Client)
*/
#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

#define MAX_SIZE 512

struct dataBuff
{
	long iMsgType;
	char data[MAX_SIZE];
};

int main(int argc, char const **argv)
{
	//variables
	int iRet = -1;
	int iMsgqId = -1;
	int iRunning = 1;
	char chBuff[MAX_SIZE];
	struct dataBuff pkt1;
	key_t key = ftok(".",1);

	if((iMsgqId = msgget((key_t)key,IPC_CREAT|0666)) == -1)
	{
		printf("[ERROR] message queue cannot get\n");
		return(-1);
	}

	pkt1.iMsgType = 151;

	while(iRunning)
	{

		fputs("[INPUT] Data: ",stdout);
		fgets(chBuff,MAX_SIZE,stdin);

		strcpy(pkt1.data,chBuff);

		if((iRet = msgsnd(iMsgqId,(void *)&pkt1,MAX_SIZE,0))==-1)
		{
			printf("[ERROR] message cannot send\n");
			return(-1);
		}

		if((strncmp(pkt1.data,"end",3)) == 0)
		{
			printf("[INFO] End\n");
			iRunning = 0;
		}

	}

	return(0);
}