#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>	//for unlink()
#include<string.h>
#include<sys/stat.h>	//for stat()
#include<dirent.h>	//for opendir(),readdir()

//Function Declaration
char* getFullPathWithFileName(char[] , char[]);
long getFileSize(char *,struct stat *);

//entry point
int main(int argc, char **argv)
{
	//variable declaration
	long iMaxSize = 0;
	int iRet = 0;
	int idelCnt = 0;
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
		//read directory content
		while((psDirInfo = readdir(pDir)) != NULL)
		{
			if((*psDirInfo).d_type != DT_DIR )
			{
				chFileNameWithPath = getFullPathWithFileName(chFolderName,(*psDirInfo).d_name);

				iMaxSize = getFileSize(chFileNameWithPath,&sFileStat);

				if(iMaxSize == 0)
				{
					iRet = unlink(chFileNameWithPath);
					if(iRet == 0)
					{
						idelCnt += 1;
						printf("[INFO] Deleted File : %s\n",chFileNameWithPath);
					}
				}

				free(chFileNameWithPath);
			}
		}

		printf("[INFO] Deleted Empty Files : %d\n", idelCnt);

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
