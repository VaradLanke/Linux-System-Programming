/*
	A9_05 : Program which is used to get thread id 
			inside its thread function.
*/
#include<stdio.h>
#include<pthread.h>

void *ThreadProc(void *);

int main(int argc, char const *argv[])
{
	//variable
	pthread_t sThread;

	pthread_create(&sThread,NULL,ThreadProc,NULL);

	pthread_join(sThread,NULL);

	return(0);
}

void *ThreadProc(void *vpParam)
{
	printf("[INFO] Inside ThreadProc\n");
	printf("[INFO] Thread id: %ld\n",pthread_self());
}