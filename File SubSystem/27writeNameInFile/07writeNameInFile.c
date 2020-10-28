#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int argc,char **argv)
{
	//variable initialization
	int iFd = 0;
	int iNameSize = 0;
	int iRet = 0;
	char *chName = NULL;
	char *chFileName = NULL;

	//argument validation
	if(argc != 3)
	{
		printf("[ERROR] Insufficient argument\n");
		return(-1);
	}

	//argument processing
	chFileName = malloc(strlen(argv[1]));
	chFileName = argv[1];
	iNameSize = strlen(argv[2]);
	chName = malloc(iNameSize);
	chName = argv[2];
	printf("[INFO] Data :  %s\n",chName );

	//open
	iFd = open(chFileName,O_WRONLY);

	//checkopen status
	if(iFd == -1)
	{
		printf("[ERROR] Unable to open File\n");
		printf("[CHECK] Please check whether file exists\n");
		return(-1);
	}

	//write
	iRet = write(iFd,chName,iNameSize);

	//check write
	if(iRet == -1)
	{
		printf("[ERROR] Unable to write into File\n");
		close(iFd);
		return(-1);
	}
	
	printf("[INFO] Written Bytes into File : %d\n",iRet);

	close(iFd);

	return(0);
}