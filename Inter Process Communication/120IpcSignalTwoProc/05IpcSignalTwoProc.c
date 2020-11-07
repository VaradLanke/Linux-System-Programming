/*
	A12_05 : Program which creates two process as 
			 sender and receiver in which sender 
			 process send signal to receiver process.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>
#include<sys/wait.h>

void handler_signal(int);

int main(int argc, char **argv)
{
	int wsStatus = -1;
	pid_t iChildPid1 = -1;
	pid_t iChildPid2 = -1;
	char strChildPid[512];

	switch(iChildPid1 = fork())
	{
		case -1:
			printf("[ERROR] fork() failed!\n");
			break;
		case 0:
			execl("receiver","",NULL);
			break;
		default:
			sleep(1);
			if((iChildPid2=fork()) == 0)
			{
				sprintf(strChildPid,"%d",iChildPid1);
				execl("sender",strChildPid,NULL);
			}

			while(wait(&wsStatus) < 0);

			break;
	}

}