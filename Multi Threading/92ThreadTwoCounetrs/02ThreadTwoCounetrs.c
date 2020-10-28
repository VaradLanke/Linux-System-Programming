/*
	A9_02 : Program which creates two thread , first thread
	 		print numbers from 1 to 500 & other thread prints the 
	 		numbers from 500 to 1.
*/
#include<stdio.h>
#include<pthread.h>

void *ThreadProc1(void *);
void *ThreadProc2(void *);

int main(int argc, char const *argv[])
{
	//variables
	pthread_t sThread1;
	pthread_t sThread2;
	int iRet1 = -1;
	int iRet2 = -1;

	iRet1 = pthread_create(&sThread1,NULL,ThreadProc1,NULL);
	iRet2 = pthread_create(&sThread2,NULL,ThreadProc2,NULL);

	if(iRet1!=0)
	{
		printf("[ERROR] ThreadProc1 failed to create : %d\n",iRet1);
	}
	if(iRet2!=0)
	{
		printf("[ERROR] ThreadProc2 failed to create : %d\n",iRet2);
	}

	pthread_join(sThread1,NULL);
	pthread_join(sThread2,NULL);

	return(0);
}

void *ThreadProc1(void *vpParam)
{
	printf("[INFO] Inside ThreadProc1\n");
	int i = 0;
	for(i=0;i<=500;i++)
	{
		printf("[ThreadProc1] %d\n",i);
	}
	pthread_exit(NULL);
}

void *ThreadProc2(void *vpParam)
{
	printf("[INFO] Inside ThreadProc2\n");
	int i = 500;
	for(i=500;i>=0;i--)
	{
		printf("[ThreadProc2] %d\n",i);
	}
	pthread_exit(NULL);
}