/*
	A8_03 : Write a program which creates one process which accept one 
			directory name. That process will rename all names of 
			regular files with sequential number.
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char const **argv)
{
	//variable initializaton
	int iRet = 0;
	int wStatus = 0;

	switch(iRet = fork())
	{
		case -1:
			printf("[ERROR] fork() failed!\n");
			return(-1);
		case 0:	//child
			printf("[INFO] Rename Process Created : %d\n",getpid());
			execl("./03RenameProc.o","",argv[1],NULL,NULL);
			break;
		default:	//parent
			wait(&wStatus);
			if(WIFEXITED(wStatus) == 1)
			{
				printf("[INFO] Rename Process terminated\n");
			}
			break;
	}

	return(0);
}