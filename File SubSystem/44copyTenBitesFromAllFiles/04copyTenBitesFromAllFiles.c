/*
A4_04 : Program which accepts directory name from user 
		and copy first 10 bytes from all regular files 
		into newly created file named as demo.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>	//for stat()
#include<dirent.h>	//for opendir(),readdir() structs
#include<fcntl.h>	// for O_RDONLY
#include<unistd.h>	//for read()

//Function Declaration
char* getFullPathWithFileName(char[] , char[]);
int getBytesFromFile(char*, char*, int);
int writeDataIntoFile(char*, char*, int);

//entry point
int main(int argc, char **argv)
{
	//variable declaration
	long iSize = 0;
	char eachFileData[10];
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
	chFolderName = argv[1];

	//open directory
	pDir = opendir(chFolderName);

	if(pDir)
	{
		//read directory content
		while((psDirInfo = readdir(pDir)) != NULL)
		{
			if((*psDirInfo).d_type != DT_DIR )
			{
				chFileNameWithPath = getFullPathWithFileName(chFolderName,(*psDirInfo).d_name);
				getBytesFromFile(chFileNameWithPath,eachFileData,10);
				free(chFileNameWithPath);

				chFileNameWithPath = getFullPathWithFileName(".","demo.txt");
				writeDataIntoFile(chFileNameWithPath,eachFileData,10);
				free(chFileNameWithPath);
			}
		}

		printf("\n[INFO] Copied 10 bytes from all files\n");

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
 * Function Definition To get file path with folder
 */
char* getFullPathWithFileName(char chInBasePath[],char chInFileName[])
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