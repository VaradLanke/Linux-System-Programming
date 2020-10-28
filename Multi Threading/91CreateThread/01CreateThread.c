/*
	A9_01 : Program which is used to create simple thread 
			by using pthread library.
*/
#include<stdio.h>
#include<pthread.h>

void *ThreadProc(void *);

int main(int argc, char const *argv[])
{
	//variables
	pthread_t sThreadId;
	int iRet = -1;

	iRet = pthread_create(&sThreadId,NULL,ThreadProc,NULL);
	if(iRet == 0)
	{
		printf("[INFO] Thread Created Successfully\n");
	}
	else{
		printf("[ERROR] Cannot create thread : %d\n",iRet);
		return(-1);
	}

	//wait to terminate thread
	pthread_join(sThreadId,NULL);

	return(0);
}

void *ThreadProc(void *arg)
{
	printf("[INFO] Inside ThreadProc!\n");
	pthread_exit(NULL);
}