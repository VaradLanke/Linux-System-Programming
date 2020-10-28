/*
	A7_01 : Program which creates one child process, and parent process 
			waits till its child process terminates.
*/
#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc,char **argv)
{
	//variables initialization
	int childPid = -1;
	int wsStatus;

	//create process
	switch(childPid=fork())
	{
		case -1:
			printf("[ERROR] fork() failed!\n");
			return(-1);
		case 0:	//child process
			printf("[INFO] Child process executing...\n");
			printf("[INFO] Child created sucessfully\n");
			printf("[INFO] Child's Parent pid: %d\n",getppid());
			printf("[INFO] Child Pid: %d\n",getpid());
			break;
		default:	//parent process
			wait(&wsStatus); // wait for child termination
			if(WIFEXITED(wsStatus)==1)
			{
				printf("[INFO] Child exited sucessfully\n");
			}
			else{
				printf("[ERROR] Abnormal terination of child!\n");
			}

			printf("[INFO] Parent process executing...\n");
			printf("[INFO] Terminal Pid: %d\n",getppid());
			printf("[INFO] Parent Pid: %d\n",getpid());
			printf("[INFO] Child Pid: %d\n",childPid);
			break;
	}
	
	return(0);
}