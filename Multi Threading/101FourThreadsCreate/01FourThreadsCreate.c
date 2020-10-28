/*
	A10_01: Program which creates 4 number of threads and 
			our main thread waits till all the thread 
			terminates.
*/
#include<stdio.h>
#include<pthread.h>

void *ThreadProc(void *);

int main(int argc, char **argv)
{
	//variables
	pthread_t threads[4];
	int iRet = -1;

	printf("[INFO] Inside Main\n");

	//create four threads
	for (int i = 0;i < 4; ++i)
	{
		iRet = pthread_create(&threads[i],NULL,ThreadProc,(void *)i);

		if(iRet != 0)
		{
			printf("[ERROR] Unable to create %d thread\n",i);
		}
	}

	//wait for all threads to terminate
	for (int i = 0; i < 4; ++i)
	{
		pthread_join(threads[i],NULL);
	}

	printf("[INFO] Inside Main\n");

	return(0);
}

void *ThreadProc(void *vpParam)
{
	printf("[ThreadProc%d] Inside Thread %d\n",(int)vpParam,(int)vpParam);
	pthread_exit(NULL);
}
