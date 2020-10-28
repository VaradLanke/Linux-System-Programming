#include<stdio.h>
#include<stdlib.h>	//for malloc()
#include<unistd.h>  //for read(), write()
#include<string.h>
#include<fcntl.h>

int main(int argc,char **argv)
{
	//variable declaration
	int iFd = 0;
	int iRet = 0;
	int iOffset = 0;
	char *chSourceFileName = NULL;
	char *chDestFileName = NULL;
	char *chBuff = NULL;

	if(argc != 3)
	{
		printf("[ERROR] Insufficient Arguments\n");
		return(-1);
	}

	//argument processing
	chSourceFileName = argv[1];
	chDestFileName = argv[2];

	//open source file
	iFd = open(chSourceFileName,O_RDONLY);
	if(iFd == -1)
	{
		printf("[ERROR] Unable to open source file : %s\n",chSourceFileName);
		return(-1);
	}

	//get source file content size
	iOffset = lseek(iFd,0,SEEK_END);
	if(iOffset == 0)
	{
		printf("[ERROR] Source file is empty : %s\n",chSourceFileName);
		return(-1);
	}
	lseek(iFd,0,0);

	chBuff = malloc(iOffset);

	//read source file
	iRet = read(iFd,chBuff,iOffset);
	if(iRet != iOffset)
	{
		printf("[ERROR] Unable to read file content: %s\n",chSourceFileName);
		close(iFd);
		return(-1);
	}

	printf("[INFO] File Contents are : \n%s\n", chBuff);
	
	//close source file
	close(iFd);
	iFd = 0;

	//open dewstination file
	iFd = open(chDestFileName,O_WRONLY);
	if(iFd == -1)
	{
		printf("[ERROR] Unable to open destination file : %s\n",chDestFileName);
		return(-1);
	}

	//write to destination file
	iRet = write(iFd,chBuff,iOffset);
	if(iRet != iOffset)
	{
		printf("[ERROR] Unable to write data into destination file : %s\n",chDestFileName);
		close(iFd);
		return(-1);
	}

	printf("[INFO] Data Successfully cpoied into %s\n",chDestFileName);

	//close Destination file
	close(iFd);
	free(chBuff);

	return(0);
}