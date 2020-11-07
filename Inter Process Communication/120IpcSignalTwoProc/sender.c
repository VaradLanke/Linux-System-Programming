/*
	Program which sends the signals to other process
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

int main(int argc, char **argv)
{
	
	if(argc != 1)
	{
		printf("[ERROR] Insufficient arguments!\n");
		return(-1);
	}

	int iChildPid = strtol(argv[0],NULL,10);

	printf("[SENDER] Sending SIGINT\n");
	kill(iChildPid,SIGINT);
	sleep(1);

	printf("[SENDER] Sending SIGHUP\n");
	kill(iChildPid,SIGHUP);
	sleep(1);

	printf("[SENDER] Sending SIGUSR1\n");
	kill(iChildPid,SIGUSR1);
	sleep(1);

	printf("[SENDER] Sending SIGUSR2\n");
	kill(iChildPid,SIGUSR2);
	sleep(1);

	printf("[SENDER] Sending SIGQUIT\n");
	kill(iChildPid,SIGQUIT);
	sleep(1);


	return(0);
}