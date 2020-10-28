/*
	A7_02 : Program which creates three level process hierarchy where 
			process 1 creates process 2 and it internally creates process 3.

	Logic :
		step 1) p1 creates p2
		step 2) p2 creates p3
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc,char **argv)
{
	//variables initialization
	int processId = 0; // new process pid
	int pStatus = 0;	// status of wait sys call
	int tPid = 0;	//pid of terminated process(returned by wait sys call)

	printf("[INFO] Process Main pid: %d | (level 1)\n",getpid());

	//create process 2
	switch(processId=fork())
	{
		case -1:
			printf("[ERROR] fork() failed! (pid: %d)\n",getpid());
			return(-1);

		case 0:	//child process
			printf("<INFO> Process PPid: %d (creates process)--> Pid: %d | (level 2)\n",getppid(),getpid());

			//create process 3
			if((processId=fork())==0)
			{
				printf("<INFO> Process PPid: %d (creates process)--> Pid: %d | (level 3)\n",getppid(),getpid());
			}
			else
			{
				tPid = wait(&pStatus);
				if(WIFEXITED(pStatus)==1)
					printf("[INFO] Terminated process: %d (return to parent)--> pid: %d\n",tPid,getpid());
			}
			break;

		default:	//parent process
			tPid = wait(&pStatus);
			if(WIFEXITED(pStatus)==1)
				printf("[INFO] Terminated process: %d (return to parent)--> pid: %d\n",tPid,getpid());
			break;
	}

	return(0);
}