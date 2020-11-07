/*
	Program for Reading from named pipe
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char **argv)
{
	int iRet = -1;
	int iFd = -1;
	char chBuff[512];
	char *file = "/tmp/fifo_file";

	printf("<READER> pid: %d \n",getpid());

	sleep(1);

	iFd = open(file,O_RDONLY);
	if(iFd == -1)
	{
		printf("[ERROR] Cannor read fifo_file\n");
		return(-1);
	}

	iRet = read(iFd,chBuff,sizeof(chBuff));
	printf("<READER> Data: %s\n",chBuff);

	close(iFd);

	return(0);
}