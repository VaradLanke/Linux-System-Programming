/*
	A8_01 : program which creates new process which is responsible 
			to write all file names which are present on desktop 
			in demo.txt file which should be created newly.
*/
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>
#include <unistd.h>

int main(int argc,char **argv)
{
	//variables initialization
	int childPid = -1;
	int wsStatus;

	printf("[INFO] Parent Pid: %d\n",getpid());

	//create process
	switch(childPid=fork())
	{
		case -1:
			printf("[ERROR] fork() failed!\n");
			return(-1);
		case 0:	//child process
			printf("<INFO> myProc Pid: %d\n",getpid());
			execl("./myProc","",NULL,NULL);
			break;
		default:	//parent process
			wait(&wsStatus); // wait for child termination
			if(WIFEXITED(wsStatus)==1)
			{
				printf("<INFO> myProc exited sucessfully\n");
			}
			else{
				printf("[ERROR] Abnormal terination of child!\n");
			}
			break;
	}
	
	return(0);
}