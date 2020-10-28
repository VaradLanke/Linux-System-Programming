/*
	A10_04: Program which creates two thread , and by using
	 		appropriate synchronization technique avoid the 
	 		scheduling problem.
*/
#include<stdio.h>
#include<pthread.h>

int iCounter;
pthread_mutex_t lock; //global lock variable

void *ThreadProc(void *);

int main(int argc, char **argv)
{
	//variables
	pthread_t thread_1;
	pthread_t thread_2;
	int iRet = -1;

	//initialize mutex
	if(pthread_mutex_init(&lock,NULL) != 0)
	{
		printf("[ERROR] Unable to create mutex\n");
	}

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

	//destroy mutex
	pthread_mutex_destroy(&lock);

	return(0);
}

void *ThreadProc(void *vpParam)
{
	pthread_mutex_lock(&lock);//lock the mutex object

	unsigned long i;
	iCounter++;

	printf("[INFO] Thread_%d started : %d\n",(int)vpParam,iCounter);
	for(i = 0;i<0xffffffff;++i);
	printf("[INFO] Thread_%d exiting : %d\n",(int)vpParam,iCounter);

	pthread_mutex_unlock(&lock);//unlock the mutex object
	pthread_exit(NULL);
}