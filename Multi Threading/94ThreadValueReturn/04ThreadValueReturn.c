/*
	A9_04 : Program which creates single thread and it 
			accept one value from user and it return 
			some value to the caller thread.
*/
#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

void *ThreadProc(void *);

int main(int argc, char const *argv[])
{
	//variables
	pthread_t sThread;
	int iArgument = 4;
	int *iRet;

	pthread_create(&sThread,NULL,ThreadProc,(void *)&iArgument);
	pthread_join(sThread,(void*)iRet);

	printf("[INFO] Square(returned value) : %d\n",*iRet);

	return(0);
}

void *ThreadProc(void *vpParam)
{
	int iParameter = *(int*)vpParam;
	printf("[INFO] Parameter : %d\n",iParameter);

	void *iVal = (int*) malloc(sizeof(int));
	iVal = (void *)(iParameter * iParameter);

	pthread_exit(iVal);
}