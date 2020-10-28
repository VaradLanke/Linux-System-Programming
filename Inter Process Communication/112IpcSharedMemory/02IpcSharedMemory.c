/*
	A11_02: Program which creates two processess and that two 
			processess can communicate with each other by using 
			concept of shared memory.
*/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main(int argc, char const **argv)
{
	int iRet = -1;
	int iStatus = -1;
	pid_t iChildpid = -1;

	switch((iChildpid = fork()))
	{
		case -1:
			printf("[ERROR] fork() failed!\n");
			break;
		case 0:	//child
			printf("<SERVER> child1 created : %d\n",getpid());
			execl("proc1","",NULL,NULL);
			break;
		default:
			if((iChildpid = fork()) == 0)
			{
				printf("<CLIENT> child2 created : %d\n",getpid());
				execl("proc2","",NULL,NULL);
			}

			while((wait(&iStatus)) == 0)
			{
				printf("...\n");
			}
			printf("[INFO] Child processes completed.\n");
			break;
	}

	
	return(0);
}