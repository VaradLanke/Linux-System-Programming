/*
	A12_01: Program which creates two process as 
			reader and writer and that processess
			should communicate with each other 
			using FIFO.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>
#include<sys/types.h>

int main(int argc, char **argv)
{
	pid_t iChildPid;
	int iWsStatus = 0;

	switch((iChildPid = fork()))
	{
		case -1:
		printf("[ERROR] fork() failed!\n");
			break;
		case 0:
			execl("writer","",NULL);
			break;
		default:
			//wait(&iWsStatus);
			if((iChildPid = fork()) == 0){
				execl("reader","",NULL);
			}
			wait(&iWsStatus);
			wait(&iWsStatus);
			printf("[PARENT] Exiting parent...\n");
			break;
	}


	return(0);
}