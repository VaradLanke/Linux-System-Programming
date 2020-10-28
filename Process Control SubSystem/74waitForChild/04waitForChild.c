/*
	A7_04 : Program which creates two processess as process2 and 
			process3 and our parent process waits till both the 
			processess terminates.

	Logic :
		step 1) p1 creates p2
		step 2) p1 creates p3
		step 3) p1 waits for p2 termination
		step 4) p1 waits for p3 termination

*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int createProcess(char*);

int main(int argc,char **argv)
{

	printf("[INFO] Process Main pid: %d\n",getpid());
	printf("---------------------------\n");

	if(argc != 3)
    {
        //command usage
        printf("[ERROR] Arguments missing.\n");
        return(-1);
    }

	//create processes
	createProcess(argv[1]);	//step 1) p1 creates p2
	createProcess(argv[2]);	//step 2) p1 creates p3

	return(0);
}

/*
** Function to create new process
*/
int createProcess(char* executableName)
{
	int processId = 0;
	int pStatus = 0;
	int tPid = 0;

	switch(processId=fork())
	{
		case -1:
			printf("[ERROR] fork() failed! (pid: %d)\n",getpid());
			return(-1);

		case 0:	//child process
			printf("<INFO> Process PPid: %d (creates process)--> Pid: %d \n",getppid(),getpid());
			
			//execute the input executable
			char* execName = (char *)malloc(sizeof(char));
			sprintf(execName,"./%s",executableName);  //concatinate strings
			execl(execName,"","20","10",NULL);
			free(execName);
			break;

		default:	//parent process
			tPid = wait(&pStatus);	//step 3 or 4) p1 waits for p2 or p3
			printf("[INFO] Wait : Pid-%d is waiting to terminate process: %d\n",getpid(),tPid);
			if(WIFEXITED(pStatus)==1)
				printf("[INFO] Terminated process: %d (return to parent)--> pid: %d\n",tPid,getpid());
				printf("---------------------------\n");
			break;
	}

	return(0);
}