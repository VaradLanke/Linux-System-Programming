/*
	A9_03 : program which creates single thread and 
			we have to pass parameter to that thread from 
			main thread.
*/
#include<stdio.h>
#include<pthread.h>

void* ThreadProc(void *);

int main(int argc, char const *argv[])
{
	//variables
	pthread_t sThreadId;
	int iRet = -1;
	int iParam = 25;

	iRet = pthread_create(&sThreadId,NULL,ThreadProc,(void*)&iParam);
	if(iRet == 0)
	{
		printf("[INFO] Thread Created Successfully: %d\n",iRet);
	}
	else{
		printf("[ERROR] Cannot create thread : %d\n",iRet);
		return(-1);
	}

	//wait to terminate thread
	pthread_join(sThreadId,NULL);

	return(0);
}

void *ThreadProc(void *vpParam)
{
	int iParam = *(int*)vpParam;

	printf("[INFO] Inside ThreadProc!\n");
	printf("[INFO] Parameter : %d\n",iParam);

	pthread_exit(NULL);
}
