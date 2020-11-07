/*
	Program which handles signals.
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
	signal(SIGUSR1,handler_signal);
	signal(SIGUSR2,handler_signal);

	printf("[RECIEVER] Receiver Wating for Signal...\n\n");
	for(;;);

	return(0);
}

void handler_signal(int iSignum)
{
	switch(iSignum) {

		case SIGUSR1:
			signal(SIGUSR1,handler_signal);
			printf("[RECIEVER] Received SIGUSR1.\n\n");
			break;

		case SIGUSR2:
			signal(SIGUSR2,handler_signal);
			printf("[RECIEVER] Received SIGUSR2.\n\n");
			break;

		case SIGHUP:
			signal(SIGHUP,handler_signal);
			printf("[RECIEVER] Received SIGHUP.\n\n");
			break;

		case SIGINT:
			signal(SIGHUP,handler_signal);
			printf("[RECIEVER] Received SIGINT.\n\n");
			break;

		case SIGQUIT:
			printf("[RECIEVER] Received SIGQUIT, Killed by parent.\n");
			exit (0);

		default:
			printf("[RECIEVER] Received %d Signal\n", iSignum);
			return;
	}
}