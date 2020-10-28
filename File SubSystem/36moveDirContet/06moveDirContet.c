#include<stdio.h>
#include<string.h>
#include<unistd.h>	//for read()
#include<fcntl.h>	//for file modes
#include<stdlib.h>	//fr malloc
#include<dirent.h>	//for readdir(),writedir()
#include<sys/stat.h>	//for stat()

//Function Declaration
char* getFullPathWithFileName(char[] , char[]);
void copyEachFile(char[],char[]);

//entry point
int main(int argc,char **argv)
{
	//variable initialization
	char *chSourceDirName = NULL;
	char *chDestDirName = NULL;
	DIR *pSourceDir = NULL;
	DIR *pDestDir = NULL;
	struct dirent *psSourceDirInfo = NULL;
	struct dirent *psDestDirInfo = NULL;
	struct stat psSourceFileStat;
	struct stat psDestFileStat;

	char *chSrcFileNameWithPath = NULL;
	char *chDestFileNameWithPath = NULL;

	//argument validation
	if(argc != 3)
	{
		printf("[ERROR] Insufficient Arguments\n");
		return(-1);
	}

	//argument processing
	chSourceDirName = argv[1];
	chDestDirName = argv[2];

	//open source & destination directories
	pSourceDir = opendir(chSourceDirName);
	pDestDir = opendir(chDestDirName);

	if(pSourceDir == NULL || pDestDir == NULL)
	{
		printf("[ERROR] Unable to open given directories\n");
		return(-1);
	}

	//read directory contents
	while((psSourceDirInfo = readdir(pSourceDir)) != NULL)
	{
		if((*psSourceDirInfo).d_type != DT_DIR)
		{
			// printf("[INFO] File : %s\n", (*psSourceDirInfo).d_name);
			chSrcFileNameWithPath = getFullPathWithFileName(chSourceDirName,(*psSourceDirInfo).d_name);
			chDestFileNameWithPath = getFullPathWithFileName(chDestDirName,(*psSourceDirInfo).d_name);

			//printf("[INFO] srcfullPath: %s\n", chSrcFileNameWithPath);
			//printf("[INFO] destfullPath: %s\n", chDestFileNameWithPath);
			copyEachFile(chSrcFileNameWithPath,chDestFileNameWithPath);
		}
	}

	return(0);
}

/*
 * Function Definition To get file path with folder
 */
char* getFullPathWithFileName(char chInBasePath[], char chInFileName[])
{
	char *retFilePath = malloc(strlen(chInBasePath)+strlen(chInFileName)+1);

	strcat(retFilePath,chInBasePath); // concat folder name
	
	//check if last character is '/'
	if((chInBasePath[strlen(chInBasePath)-1]) != '/')
	{
		strcat(retFilePath,"/");
	}

	strcat(retFilePath,chInFileName); // concat file name

	return(retFilePath);
}


void copyEachFile(char chSourceFileWithPath[],char chDestFileWithPath[])
{
	int iFd = 0;
	int iRet = 0;
	int iOffset = 0;
	char *chBuff = NULL;

	int iDestFd = 0;

	//open file ; create if not
	iFd = open(chSourceFileWithPath,O_RDONLY);
	if(iFd == -1)
	{
		printf("[ERROR] Unable to open source file: %s\n",chSourceFileWithPath);
		return;
	}

	//lseek to get source file content size
	iOffset = lseek(iFd,0,SEEK_END);
	if(iOffset <= 0)
	{
		printf("[ERROR] Source file is empty : %s\n",chSourceFileWithPath);
		return;
	}
	lseek(iFd,0,0);

	chBuff = malloc(iOffset*2);

	//read source file
	iRet = read(iFd,chBuff,iOffset);
	if(iRet != iOffset)
	{
		printf("[ERROR] Unable to read file content: %s\n",chSourceFileWithPath);
		close(iFd);
		return;
	}

	//open destination file; create if not present
	printf("[--]%s\n",chDestFileWithPath );
	iDestFd = open(chDestFileWithPath,O_CREAT|O_WRONLY);
	printf("[create]: %d\n", iDestFd);
	// close(iDestFd);
	// iDestFd = open(chDestFileWithPath,O_WRONLY);
	if(iDestFd == -1)
	{
		printf("[ERROR] Unable to open destination file: %s\n",chDestFileWithPath);
		return;
	}

	//write all contents to destination file
	iRet = write(iDestFd,chBuff,iOffset);

	//close file resources
	close(iDestFd);
	close(iFd);
	free(chBuff);

}