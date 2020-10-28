/*
	A10_03: Program which is used to predict the problem 
			due to lack of synchronization.

	Problem: Two threads increments global counter and 
			 sets  wrong  value  because of   lack  of
			 synchronization
*/
#include<stdio.h>
#include<pthread.h>

int iCounter; //global variable set to 0

void *ThreadProc(void *);

int main(int argc, char **argv)
{
	//variables
	pthread_t thread_1;
	pthread_t thread_2;
	int iRet = -1;

	iRet = pthread_create(&thread_1,NULL,ThreadProc,(void *)1);
	if(iRet != 0)
	{
		printf("[ERROR] Unable to create thread_1\n");
	}
	iRet = pthread_create(&thread_2,NULL,ThreadProc,(void *)2);
	if(iRet != 0)
	{
		printf("[ERROR] Unable to create thread_2\n");
	}

	pthread_join(thread_1,NULL);
	pthread_join(thread_2,NULL);

	return(0);
}

void *ThreadProc(void *vpParam)
{
	unsigned long i;
	iCounter++;

	printf("[INFO] Thread_%d started : %d\n",(int)vpParam,iCounter);
	for(i = 0;i<0xffffffff;++i);
	printf("[INFO] Thread_%d exiting : %d\n",(int)vpParam,iCounter);

	pthread_exit(NULL);
}