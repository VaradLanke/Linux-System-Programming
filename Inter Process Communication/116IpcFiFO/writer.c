/*
	Program for Writing into named pipe
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv)
{
	int iRet = -1;
	int iFd = -1;
	char chBuff[512] = "abcdefghijklmnopqrstuvwxyz";
	char *file = "/tmp/fifo_file";

	printf("<WRITER> pid: %d \n",getpid());

	iRet = mkfifo(file,0666);
	if(iRet == -1)
	{
		printf("[ERROR] mkfifo() failed!\n");
		return(-1);
	}

	iFd = open(file,O_WRONLY);
	if(iFd == -1)
	{
		printf("[ERROR] cannot open fifo_file.\n");
		return(-1);
	}

	iRet = write(iFd,chBuff,sizeof(chBuff));

	printf("<WRITER> Written Data: %d\n",iRet);

	unlink(file);
	close(iFd);

	return(0);
}