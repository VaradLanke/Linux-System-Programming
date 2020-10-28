/*
	A11_01: Program which is used to create unnamed pipe.
	 		Parent process creates new child process and 
	 		both the processess will communicate with each other.
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
	char data[] = "aAbBcCdDeeffgghh";
	char buffer[50];

	pipe(iFd);

	childpid = fork();

	if(childpid == 0)
	{
		close(iFd[0]);

		ret = write(iFd[1],data,sizeof(data)+1);

		printf("[CHILD] Written data : %d\n",ret);

		exit(0);
	}
	else
	{
		close(iFd[1]);

		ret = read(iFd[0],buffer,sizeof(buffer));
		
		printf("[PARENT] Received Data: %s\n",buffer);
	}
	
	return(0);
}