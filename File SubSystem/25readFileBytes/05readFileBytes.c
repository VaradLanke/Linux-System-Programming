#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<time.h>

//Function declaration
void printFileInfo(struct stat,char *);

//Entry point
int main(int argc,char **argv)
{
	//variable initialization
	int iFd = 0;
	int iByteSize = 0;
	int iRet = 0;
	char *cpBuff = NULL;
	char *cpFileName = NULL;

	if(argc != 3)
	{
		printf("[ERROR] Insufficient Arguments\n");
		return(-1);
	}

	//Argument processing
	cpFileName = malloc(strlen(argv[1]));
	cpFileName = argv[1];
	iByteSize = strtol(argv[2],NULL,10);
	cpBuff = malloc(iByteSize*2);

	//open file
	iFd = open(cpFileName,O_RDONLY);

	//check open status
	if(iFd == -1)
	{
		printf("[ERROR] Unable to read File\n");
		printf("[CHECK] Please check File exists\n");
		return(-1);
	}

	printf("[INFO] File Opened Successfully with fd : %d\n",iFd);

	//read file
	iRet = read(iFd,cpBuff,iByteSize);

	//check read status
	if(iRet != iByteSize)
	{
		printf("[ERROR] Unable to read contents of file\n");
		close(iFd);
		return(-1);
	}
	
	printf("[INFO] File Contents are : \n%s\n",cpBuff);

	//free resources
	close(iFd);
	free(cpBuff);

	return(0);

}