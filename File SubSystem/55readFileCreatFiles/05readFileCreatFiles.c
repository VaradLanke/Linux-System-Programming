/*
A5_05 : Program which accepts file name which contains
		data of all file and then creates all file again.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>	//for stat()
#include<dirent.h>	//for opendir(),readdir() structs
#include<fcntl.h>	// for O_RDONLY
#include<unistd.h>	//for read()
#include<libgen.h>	//for basename()

//Function Declaration
char* getFullPathWithFileName(char[] , char[]);
int getBytesFromFile(char*, char*, int);
int writeDataIntoFile(char*, char*, int);
int getSizeOfFile(char *);
long getFileSize(char *);

//entry point
int main(int argc, char **argv)
{
	//variable declaration
	long iSize = 0;
	char *eachFileData;
	char *chFileName = NULL;
	char *chFolderName = NULL;
	char *chFileNameWithPath = NULL;
	DIR *pDir = NULL;
	struct dirent *psDirInfo = NULL;

	//argument valideation
	if(argc != 2)
	{
		printf("[ERROR] Insufficient Arguments\n");
		return(-1);
	}

	//argument processing
	chFileName = (char *)malloc(sizeof(char)*strlen(argv[1]));
	strcpy(chFileName,argv[1]);
	chFolderName = dirname(argv[1]);
	// printf("[INFO] FileName: %s\n",chFileName);
	// printf("[INFO] FolderName: %s\n",chFolderName);

	//open directory
	pDir = opendir(chFolderName);
	if(pDir)
	{
		//loop for extracting the file contents
		while((psDirInfo = readdir(pDir)) != NULL)
		{
			if((strcmp(psDirInfo->d_name,chFileName)) != 0 && (psDirInfo->d_type != DT_DIR))
			{
				chFileNameWithPath = getFullPathWithFileName(chFolderName,psDirInfo->d_name);
				iSize = getSizeOfFile(chFileNameWithPath);
				if(iSize < getFileSize(chFileName))
				{
					eachFileData = malloc(iSize);
					getBytesFromFile(chFileNameWithPath,eachFileData,iSize);

					strcat(chFileNameWithPath,"_recovered");
					writeDataIntoFile(chFileNameWithPath,eachFileData,iSize);
					free(eachFileData);
				}
				free(chFileNameWithPath);
			}
		}
	}
	else
	{
		printf("[ERROR] Cannot Open Directory in second loop\n");
		return(-1);
	}

		printf("\n[INFO] Extracted all files from %s\n",chFileName);

		//close directory
		free(chFileName);
		closedir(pDir);

	return(0);
}

/*
 * Function Definition To get file path with folder
 */
char* getFullPathWithFileName(char chInBasePath[],char chInFileName[])
{
	char *retFilePath = malloc(strlen(chInBasePath)+strlen(chInFileName)+10);

	strcat(retFilePath,chInBasePath); // concat folder name
	
	//check if last character is '/'
	if((chInBasePath[strlen(chInBasePath)-1]) != '/')
	{
		strcat(retFilePath,"/");
	}

	strcat(retFilePath,chInFileName); // concat file name

	return(retFilePath);
}

/*
 * Function Definition To get file size
 */
int getBytesFromFile(char *chFileName,char *chBuff, int iBytes)
{
	//local variables
	int iFd = 0;
	int iRet = 0;

	iFd = open(chFileName,O_RDONLY);
	printf("[INFO] file :%s\n",chFileName);
	if(iFd == -1)
	{
		printf("[ERROR] Cannot Open File: %s",chFileName);
		return(-1);
	}

	//read file upto given bytes
	iRet = read(iFd,chBuff,iBytes);

	//close
	close(iFd);

	return(iRet);
}

int writeDataIntoFile(char *chFileName,char *chBuff, int iBytes)
{
	//local variables
	int iFd = 0;
	int iRet = 0;

	//read or create demo.txt
	iFd = open(chFileName,O_APPEND|O_WRONLY|O_CREAT,0644);
	if(iFd == -1)
	{
		printf("[ERROR] Cannot Open File: %s",chFileName);
		return(-1);
	}

	//write data into file
	iRet = write(iFd,chBuff,iBytes);
	//close resources
	close(iFd);

	return(iRet);
}

int getSizeOfFile(char *chInFileName)
{
	int iFd = 0;
	int iSize = 0;
	//open that file
	iFd = open(chInFileName,O_RDONLY);
	iSize = lseek(iFd,0,SEEK_END);
	if(iSize == -1)
	{
		printf("[ERROR] Unable to find the size of file: %s\n",chInFileName);
		close(iFd);
		return(-1);
	}
	lseek(iFd,0,0);

	close(iFd);

	return iSize;
}

/*
 * Function Definition To get file size
 */
long getFileSize(char *chFileName)
{
	//local variable
	struct stat sFileStat;

	//stat sys call prototype : int stat(const char *path, struct stat *buf);
	if(stat(chFileName,&sFileStat) == 0)
	{
		return(sFileStat.st_size);
	}
	else
	{
		printf("[ERROR] Unable to fetch File Properties : %s\n\n", chFileName);
	}

	return(-1);
}