/*
	A11_04: Program which creates one child process , 
			child process write something in unamed 
			pipe and parent process read the data 
			from that pipe.
*/
#include<stdio.h>
#include<sys/mman.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

int main(int argc, char const *argv[])
{
	//variables
	int iFd = -1;
	int iSize = 100 * sizeof(int);
	int *ipShared = NULL;
	int iWstatus;
	char ch[512];
	pid_t iChildPid = -1;

	//void *vpAddr = mmap(0,iSize,PROT_READ|PROT_WRITE,MAP_SHARED|MAP_ANONYMOUS,-1,0);
	iFd = open("data", O_RDWR | O_CREAT | O_TRUNC, 0600);

	lseek(iFd,iSize,SEEK_SET);
	write(iFd,"A",1);

	void *vpAddr = mmap(NULL,iSize,PROT_READ|PROT_WRITE,MAP_SHARED,iFd,0);
	printf("[INFO] Mapped at : %p\n",vpAddr);

	ipShared = vpAddr;

	// ipShared[0] = 'Y';
   	// ipShared[1] = 'Z';

	switch((iChildPid = fork()))
	{
		case -1:
			printf("[ERROR] Cannot create child process\n");
			break;
		case 0:	//child
			ipShared[0] = 'A';
			ipShared[1] = 30;
			printf("[CHILD] Written Values : %c , %d\n",ipShared[0], ipShared[1]);
			break;
		default:	//parent
			wait(&iWstatus);
			printf("[PARENT] Read Values: %c , %d \n",ipShared[0], ipShared[1]);
			break;
	}

	munmap(vpAddr,iSize);
	close(iFd);

	return(0);
}
