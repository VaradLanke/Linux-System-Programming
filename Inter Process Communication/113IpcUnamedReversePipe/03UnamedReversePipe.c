/*
	A11_03: Program which creates one child process, 
			child process write something in unamed 
			pipe and parent process read the data 
			from that pipe.
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include <sys/wait.h>
#include<stdlib.h>

int main(int argc, char const **argv)
{
	int iFd[2],ret=0;
	pid_t childpid;
	char data[] = "hahahaha";
	char buffer[50];

	pipe(iFd);

	childpid = fork();

	if(childpid == 0)
	{
		close(iFd[1]);	//close write fd

		ret = read(iFd[0],buffer,sizeof(buffer));	//read data

		printf("[CHILD] Received Data: %s\n",buffer);

		exit(0);
	}
	else
	{
		close(iFd[0]);	//close read fd

		ret	= write(iFd[1],data,sizeof(data)+1);	//write data

		printf("[PARENT] Written data : %d\n",ret);
	}
	
	return(0);
}