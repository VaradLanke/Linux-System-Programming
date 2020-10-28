/*
	A11_05: Program which performs interprocess communication 
			using the concept of message queue.(Server)
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
	struct dataBuff pkt1;
	key_t key = ftok(".",1);

	if((iMsgqId = msgget((key_t)key,0666)) == -1)
	{
		printf("[ERROR] message queue cannot get\n");
		return(-1);
	}

	while(iRunning)
	{
		if((iRet = msgrcv(iMsgqId,(void *)&pkt1,MAX_SIZE,151,0)) ==-1)
		{
			printf("[ERROR] message cannot receive\n");
			return(-1);
		}

		printf("[INFO] Data Received : %s",pkt1.data);

		if((strncmp(pkt1.data,"end",3)) == 0)
		{
			iRunning = 0;
			printf("[INFO] End Received\n");
		}

	}

	return(0);
}