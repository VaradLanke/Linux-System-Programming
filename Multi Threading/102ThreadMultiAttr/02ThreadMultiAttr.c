/*
	A10_02: Program which creates multiple threads and 
			sets its thread attributes accordingly.
*/
#include<stdio.h>
#include<pthread.h>

void *ThreadProc(void *);

int main(int argc,char **argv)
{
	//variables
	pthread_t threads[3];
	pthread_attr_t sAttr;
	int iRet = -1;

	//initialize thread attributes
	iRet = pthread_attr_init(&sAttr);
	if(iRet != 0)
	{
		printf("[ERROR] Unablt to initialize attribute\n");
		return(-1);
	}

	pthread_attr_setdetachstate(&sAttr,PTHREAD_CREATE_JOINABLE);

	//create three threads
	for (int i = 0; i < 3; ++i)
	{	

		iRet = pthread_create(&threads[i],&sAttr,ThreadProc,(void *)i);

		if(iRet != 0)
		{
			printf("[ERROR] Unablt to create %d thread\n",i);
		}

	}

	//wait for threads to terminate
	for (int i = 0; i < 3; ++i)
	{
		pthread_join(threads[i],NULL);
	}

	return(0);
}

void *ThreadProc(void *vpParam)
{
	printf("[INFO] Sleeping in thread_%d...\n",(int)vpParam);
	sleep(1);
	printf("[INFO] Exiting thread %d\n",(int)vpParam);
}