/*
	A10_05:	program which creates two threads by using pthread API,
			where one thread count number of capital characters 
			from demo.txt file and other threads count number of 
			small characters from same file.
*/
#include<stdio.h>
#include<pthread.h>
#include<fcntl.h>
#include<unistd.h>

void *ThreadProc1(void *);
void *ThreadProc2(void *);

int main(int argc, char **argv)
{
	//variables
	pthread_t sThread1,sThread2;
	int iRet = -1;

	iRet = pthread_create(&sThread1,NULL,ThreadProc1,NULL);
	if(iRet != 0)
	{
		printf("[ERROR] Unable to create thread_1\n");
	}
	iRet = pthread_create(&sThread2,NULL,ThreadProc2,NULL);
	if(iRet != 0)
	{
		printf("[ERROR] Unable to create thread_2\n");
	}

	pthread_join(sThread1,NULL);
	pthread_join(sThread2,NULL);

	return(0);
}

void *ThreadProc1(void *vpParam)
{

	//pthread_mutex_lock(&lock);

	int iFd = -1;
	int iRet = -1;
	int iCapCounter = 0;
	char buffer[512];

	iFd = open("demo.txt",O_RDONLY);
	if(iFd == -1)
	{
		printf("[ERROR] Cannot open 'demo.txt'\n");
		pthread_exit(NULL);
	}
	while((iRet = read(iFd,buffer,sizeof(buffer))) != 0)
	{
		for(int i=0;i<iRet;++i)
		{
			if(buffer[i]>='A' && buffer[i]<='Z')
			{
				iCapCounter++;
			}
		}
	}

	printf("[INFO] Thread_1 Capital Characters Count: %d\n",iCapCounter);

	close(iFd);

	pthread_exit(NULL);
}

void *ThreadProc2(void *vpParam)
{

	//pthread_mutex_lock(&lock);

	int iFd = -1;
	int iRet = -1;
	int iSmCounter = 0;
	char buffer[512];

	iFd = open("demo.txt",O_RDONLY);
	if(iFd == -1)
	{
		printf("[ERROR] Cannot open 'demo.txt'\n");
		pthread_exit(NULL);
	}
	while((iRet = read(iFd,buffer,sizeof(buffer))) != 0)
	{
		for(int i=0;i<iRet;++i)
		{
			if(buffer[i]>='a' && buffer[i]<='z')
			{
				iSmCounter++;
			}
		}
	}

	printf("[INFO] Thread_2 Small Characters Count: %d\n",iSmCounter);

	close(iFd);

	pthread_exit(NULL);
}