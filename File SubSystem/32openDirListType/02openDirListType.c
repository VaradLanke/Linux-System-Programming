#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>

//Function Declaration
void printFileType(int);

//entry point
int main(int argc, char **argv)
{
	//variable declaration
	DIR *pDir = NULL;
	struct dirent *psDirInfo = NULL;
	char *chFoladerName = NULL;

	//argument valideation
	if(argc != 2)
	{
		printf("[ERROR] Insufficient Arguments\n");
		return(-1);
	}

	//argument processing
	chFoladerName = malloc(strlen(argv[1]));
	chFoladerName = argv[1];

	//open directory
	pDir = opendir(chFoladerName);

	if(pDir)
	{
		printf("[INFO] Directory Opened Successfully\n");
		printf("[INFO] Directory Contents are : \n");

		//read directory
		while((psDirInfo = readdir(pDir)) != NULL)
		{
			printf("%s", (*psDirInfo).d_name);
			printFileType((*psDirInfo).d_type);
		}

		//close directory
		closedir(pDir);
	}
	else
	{
		printf("[ERROR] Cannot Open Directory\n");
		return(-1);
	}

	return(0);
}

/*
 * Function Definition To print file type using file type number
 */
void printFileType(int iTypeNumber)
{
	if(iTypeNumber == DT_BLK)
	{
		printf(" : Block Device \n");
	}
	else if(iTypeNumber == DT_CHR)
	{
		printf(" : Character Device \n");
	}
	else if(iTypeNumber == DT_DIR)
	{
		printf(" : Directory \n");
	}
	else if(iTypeNumber == DT_FIFO)
	{
		printf(" : Named Pipi(FIFO) \n");
	}
	else if(iTypeNumber == DT_LNK)
	{
		printf(" : Symbolic Link \n");
	}
	else if(iTypeNumber == DT_REG)
	{
		printf(" : Regular File \n");
	}
	else if(iTypeNumber == DT_SOCK)
	{
		printf(" : Unix Domain Socket \n");
	}
	else
	{
		//DT_UNKNOWN
		printf(" : Unknown File \n");
	}
}