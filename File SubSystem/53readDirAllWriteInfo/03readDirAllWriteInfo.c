/*
A5_03 : Program which accepts directory name from user 
		and writes information of all regular file in 
		and then reads the contents from that file.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/stat.h>	//for stat()
#include<dirent.h>	//for opendir(),readdir()
#include<fcntl.h>
#include<unistd.h>

//Function Declaration
char* getFullPathWithFileName(char[] , char[]);
long getFileSize(char *,struct stat *);

//entry point
int main(int argc, char **argv)
{
	//variable declaration
	long iSize = 0;
	long iMaxSize = 0;
	int iFd = 0;
	int iRet = 0;
	char *chFolderName = NULL;
	char *chMaxFileName = NULL;
	char *chFileNameWithPath = NULL;
	DIR *pDir = NULL;
	struct dirent *psDirInfo = NULL;
	struct stat sFileStat;

	//argument valideation
	if(argc != 2)
	{
		printf("[ERROR] Insufficient Arguments\n");
		return(-1);
	}

	//argument processing
	chFolderName = malloc(strlen(argv[1]));
	chFolderName = argv[1];

	//open directory
	pDir = opendir(chFolderName);

	if(pDir)
	{
		//oopen new file
		iFd = open("info.txt",O_CREAT|O_WRONLY,0644);
		if(iFd == -1)
		{
			printf("[ERROR] Unable to open result file\n");
			closedir(pDir);
			return(-1);
		}

		//read directory content
		while((psDirInfo = readdir(pDir)) != NULL)
		{
			if((*psDirInfo).d_type != DT_DIR )
			{
				chFileNameWithPath = getFullPathWithFileName(chFolderName,(*psDirInfo).d_name);

				iMaxSize = getFileSize(chFileNameWithPath,&sFileStat);

				iRet = write(iFd,(char *)&sFileStat,4096);
				if(iRet == -1)
				{
					printf("[ERROR] Unable to write into file\n");
					close(iFd);
					closedir(pDir);
					return(-1);
				}

				free(chFileNameWithPath);
			}
		}


		//close resources
		close(iFd);
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

/*
 * Function Definition To get file size
 */
long getFileSize(char *chFileName, struct stat *sFileStat)
{
	//stat sys call prototype : int stat(const char *path, struct stat *buf);
	if(stat(chFileName,sFileStat) == 0)
	{
		return((*sFileStat).st_size);
	}
	else
	{
		printf("[ERROR] Unable to fetch File Properties : %s\n\n", chFileName);
	}

	return(-1);
}
