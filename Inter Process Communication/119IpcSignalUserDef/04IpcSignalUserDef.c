/*
	A12_04 : Program which accept user defined 
			 signal from terminal.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void handler_signal(int);

int main(int argc, char **argv)
{
	pid_t iChildPid = -1;

	switch(iChildPid = fork())
	{
		case -1:
			break;
			printf("[ERROR] fork() failed!\n");
		case 0: //child
			signal(SIGHUP,handler_signal);
			signal(SIGINT,handler_signal);
			signal(SIGQUIT,handler_signal);
			signal(SIGUSR1,handler_signal);
			signal(SIGUSR2,handler_signal);
			for(;;);

		default://parent
			printf("[PARENT] Sending SIGINT\n");
			kill(iChildPid,SIGINT);
			sleep(1);
	
			printf("[PARENT] Sending SIGHUP\n");
			kill(iChildPid,SIGHUP);
			sleep(1);

			printf("[PARENT] Sending SIGUSR1\n");
			kill(iChildPid,SIGUSR1);
			sleep(2);

			printf("[PARENT] Sending SIGUSR2\n");
			kill(iChildPid,SIGUSR2);
			sleep(2);

			printf("[PARENT] Sending SIGQUIT\n");
			kill(iChildPid,SIGQUIT);
			sleep(1);
			break;
	}


	return(0);
}

void handler_signal(int iSignum)
{
	switch(iSignum) {

		case SIGUSR1:
			signal(SIGUSR1,handler_signal);
			printf("[CHILD] Received SIGUSR1.\n\n");
			break;

		case SIGUSR2:
			signal(SIGUSR2,handler_signal);
			printf("[CHILD] Received SIGUSR2.\n\n");
			break;

		case SIGHUP:
			signal(SIGHUP,handler_signal);
			printf("[CHILD] Received SIGHUP.\n\n");
			break;

		case SIGINT:
			signal(SIGHUP,handler_signal);
			printf("[CHILD] Received SIGINT.\n\n");
			break;

		case SIGQUIT:
			printf("[CHILD] Received SIGQUIT, Killed by parent.\n");
			exit (0);

		default:
			printf("[CHILD] Received %d Signal\n", iSignum);
			return;
	}
}