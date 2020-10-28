/*
	A7_03 : Program which creates three diffrent processess internally 
			as process2, process3, process4.

	Logic : 
		main process (1)  -----> creates new process (2)
			 |							|
			 |							|
		creates another			creates new process (4)  
		new process (3)				bcoz of same code

*/
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int createProcess();

int main(int argc,char **argv)
{

	printf("[INFO] Process Main pid: %d\n",getpid());

	//create processes
	createProcess();
	createProcess();

	return(0);
}

/*
** Function to create new process
*/
int createProcess()
{
	int processId = 0; // new process pid
	int pStatus = 0;	// status of wait sys call
	int tPid = 0;	//pid of terminated process(returned by wait sys call)

	switch(processId=fork())
	{
		case -1:
			printf("[ERROR] fork() failed! (pid: %d)\n",getpid());
			return(-1);

		case 0:	//child process
			printf("<INFO> Process PPid: %d (creates process)--> Pid: %d \n",getppid(),getpid());
			break;

		default:	//parent process
			tPid = wait(&pStatus);
			if(WIFEXITED(pStatus)==1)
				printf("[INFO] Terminated process: %d (return to parent)--> pid: %d\n",tPid,getpid());
			break;
	}

	return(0);
}