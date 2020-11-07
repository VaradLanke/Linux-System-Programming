/*
	A12_03 : Program which creates such a process 
			 which accept signals from the terminal.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void handler_signal(int);

int main(int argc, char **argv)
{
	signal(SIGHUP,handler_signal);
	signal(SIGINT,handler_signal);
	signal(SIGQUIT,handler_signal);
	for(;;);

	return(0);
}

void handler_signal(int iSignum)
{
	switch(iSignum)
	{

		case SIGHUP:
			signal(SIGHUP,handler_signal);
			printf("[INFO] SIGHUP Received\n");
			break;
		case SIGINT:
			signal(SIGINT,handler_signal);
			printf("[INFO] SIGINT Received\n");
			break;
		case SIGQUIT:
			printf("[INFO] SIGQUIT Received... Exiting\n");
			sleep(1);
			exit(0);
		default:
			printf("[INFO] UnHandled Signal: %d\n",iSignum);

	}
}