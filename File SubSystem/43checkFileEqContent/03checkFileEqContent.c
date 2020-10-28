/*
A4_03 : Program which accepts two file names from user 
		and checks whether contents of that two files 
		are equal are not.
*/
#include<stdio.h>
#include<stdlib.h> //for malloc()
#include<string.h>
#include<unistd.h>	//for read()
#include<fcntl.h>

int main(int argc,char **argv)
{
	//variable initialization
	int iFd1 = 0;
	int iFd2 = 0;
	int iRet1 = 0;
	int iRet2 = 0;
	char *chBuff1 = NULL;
	char *chBuff2 = NULL;
	char *chFileName1 = NULL;
	char *chFileName2 = NULL;

	//argument validation
	if(argc != 3)
	{
		printf("[ERROR] Insufficient Arguments\n");
		return(-1);
	}

	//argument processing
	chFileName1 = argv[1];
	chFileName2 = argv[2];

	//open files
	iFd1 = open(chFileName1,O_RDONLY);
	iFd2 = open(chFileName2,O_RDONLY);
	if(iFd1 == -1)
	{
		printf("[ERROR] Cannot open the file: %s\n",chFileName1);
		return(-1);
	}
	if(iFd2 == -1)
	{
		printf("[ERROR] Cannot open the file: %s\n",chFileName2);
		close(iFd1);
		return(-1);
	}

	//create buffers
	chBuff1 = (char *)malloc(512*sizeof(char));
	chBuff2 = (char *)malloc(512*sizeof(char));

	//read two files
	while( (iRet1 = read(iFd1,chBuff1,512)) && (iRet2 = read(iFd2,chBuff2,512)) )
	{
		printf("[INFO] reading files...%d , %d\n",iRet1,iRet2);
		if( (iRet1 != iRet2) || (strcmp(chBuff1,chBuff2) != 0))
		{
			printf("[INFO] Two files are not equal\n");
			close(iFd1);
			close(iFd2);
			return(0);
		}
		
	}

	printf("[INFO] Two files are equal\n");

	//close resources
	close(iFd1);
	close(iFd2);

	return(0);
}