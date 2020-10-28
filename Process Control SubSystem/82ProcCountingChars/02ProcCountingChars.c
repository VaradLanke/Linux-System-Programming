/*
	A8_02 : Program which creates two processess.Process 1 count number
			of capital characters from demo.txt file. And process 2 count
			number of capital characters from hello.txt file. Both the 
			processess writes its count in count.txt file.
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char const *argv[])
{
	//variable initialization
	int iProcId = 0;
	int ret1 = 0, ret2 = 0;
	int wStatus = 0;

	//argument valideation
	if(argc != 3)
	{
		printf("[ERROR] Insufficient arguments\n");
		return(-1);
	}

	switch(ret1=fork())
	{
		case -1:
			printf("[INFO] fork() faied!\n");
			break;
		case 0:
			execl("./CounterProc","",argv[1],NULL);
			break;
		default:
				if((ret2=fork()))
				{
					if(ret2 == -1)
					{
						printf("[INFO] fork() failed\n");
						return(-1);
					}
					execl("./CounterProc","",argv[2],NULL);
				}

			while((iProcId = wait(&wStatus)) > 0)
			{
				printf("[INFO] %d child terminated(status: %d)\n",iProcId,wStatus);
			}

		break;
	}

	return(0);
}