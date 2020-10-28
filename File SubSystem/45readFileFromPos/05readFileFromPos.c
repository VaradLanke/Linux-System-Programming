/*
A4_05 : Program which accepts file name and position from user 
		and reads 20 bytes from that position.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>	//for read()
#include<fcntl.h>	//for mode flags

int main(int argc, char** argv)
{
	//variable initialization
	int iFd = 0;
	int iPos = 0;
	int iRet = 0;
	char *chFileName = NULL;
	char chBuff[20];

	//argument validation
	if(argc != 3)
	{
		printf("[ERROR] Insufficient arguments\n");
		return(-1);
	}

	//argument processing
	chFileName = argv[1];
	iPos = strtol(argv[2],NULL,10); //convert char to int of base 10

	//open file
	iFd = open(chFileName,O_RDONLY);
	if(iFd == -1)
	{
		printf("[ERROR] Unable to open file: %s\n",chFileName);
		return(-1);
	}

	//lseek to the position
	lseek(iFd,iPos,SEEK_CUR);

	//read 20 bytes from file
	iRet = read(iFd,chBuff,20);
	if(iRet == -1)
	{
		printf("[ERROR] Unable to read from file: %s\n",chFileName);
		return(-1);
	}

	//print result data
	// printf("[INFO] Data :");
	write(1,"[INFO] Data: \n",15);
	write(1,chBuff,iRet);
	printf("\n");

	//close
	close(iFd);

	return(0);
}