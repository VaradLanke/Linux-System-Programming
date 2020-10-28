/*
A4_01 : Program used to demonstrate concept of I/O redirection.
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>	//for calloc
#include<unistd.h>	//to read()
#include<fcntl.h>

int main(int argc,char **argv)
{
	//variable initialization
	int iFd = 0;
	int iOpFd = 0;
	int iRet = 0;
	char *chInFileName = NULL;
	char *chOpFileName = NULL;
	char *chOutFileName = NULL;
	char *chBuff = NULL;


	if(argc != 3)
	{
		printf("[ERROR] Insufficient Arguments\n");
		return(-1);
	}

	//argument proccessing
	chInFileName = argv[1];
	chOutFileName = argv[2];

	//open the input file
	iFd = open(chInFileName,O_RDONLY);
	if(iFd == -1)
	{
		printf("[ERROR] Cannot open input the file\n");
		return(-1);
	}

	//open the oputput file
	iOpFd = open(chOutFileName,O_WRONLY|O_CREAT,0644);
	if(iOpFd == -1)
	{
		printf("[ERROR] Cannot open output the file\n");
		return(-1);	
	}

	//create buffer
	chBuff = (char *)malloc(512 * sizeof(char));

	//read the input from input file
	while((iRet = read(iFd,chBuff,512) != 0))
	{
		printf("[INFO] len(chBuff): %ld\n",strlen(chBuff));
		printf("[INFO] chBuff: %s\n", chBuff);
		if(iRet == -1)
		{
			printf("[ERROR] Unable to read from the input file\n");
			close(iOpFd);
			close(iFd);
			free(chBuff);
			return(-1);
		}

		//write into output file
		if((iRet = write(iOpFd,chBuff,strlen(chBuff))) == -1)
		{
			printf("[ERROR] Unable to write into output file\n");
			close(iOpFd);
			close(iFd);
			free(chBuff);
			return(-1);
		}
	}

	close(iOpFd);
	close(iFd);
	free(chBuff);

	return(0);
}