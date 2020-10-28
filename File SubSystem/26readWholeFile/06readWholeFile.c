#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc,char **argv)
{
	//variable initialization
	int iFd = 0;
	int iRet = 0;
	int iOffset = 0;
	char *chBuff = NULL;
	char *cpFileName = NULL;

	//check arguments
	if(argc != 2)
	{
		printf("[ERROR] Insufficient Arguments\n");
		return(-1);
	}

	//argument processing
	cpFileName = malloc(strlen(argv[1]));
	cpFileName = argv[1];

	//open file
	iFd = open(cpFileName,O_RDONLY);
	//check open status
	if(iFd == -1)
	{
		printf("[ERROR] Unable to open file\n");
		printf("[CHECK] Please check whether file exists\n");
		return(-1);
	}

	printf("[INFO] File opened successfully with fd : %d\n",iFd);

	//get content size
	iOffset = lseek(iFd,0,SEEK_END);
	//check lseek status
	if(iOffset == 0)
	{
		printf("[ERROR] File is empty\n");
		close(iFd);
		return(-1);
	}

	//set cursor to start position
	lseek(iFd,0,0);

	printf("[INFO] FileContent Size : %d\n",iOffset);
	chBuff = malloc(iOffset);

	//read
	iRet = read(iFd,chBuff,iOffset);
	//check read status
	if(iRet != iOffset)
	{
		printf("[ERROR] Unable to read File Content\n");
		close(iFd);
		return(-1);
	}

	printf("[INFO] File content are : \n%s\n",chBuff);

	//close resources
	close(iFd);
	free(chBuff);

	return(0);
}