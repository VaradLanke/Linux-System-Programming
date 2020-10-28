#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<dirent.h>

char* getFullPathWithFileName(char *, char *);

int main(int argc, char const **argv)
{
	//variable initialization
	char *chDirName = NULL;
	char *chOldPath = NULL;
	char *chNewName = NULL;
	char *chNewPath = NULL;
	int ret = 0;
	int count = 1;
	DIR *pDir = NULL;
	struct dirent *pDirEntry = NULL;

	//argument validation
	if(argc != 2)
	{
		printf("[ERROR] Insufficient Arguments\n");
		return(-1);
	}

	chDirName = (char *)malloc(sizeof(argv[1]));
	strcpy(chDirName,argv[1]);

	//open directory
	pDir = opendir(chDirName);
	if(pDir == NULL)
	{
		printf("[ERROR] Unable to open '%s' directory\n",chDirName);
		return(-1);
	}

	while((pDirEntry = readdir(pDir))!=NULL)
	{
		if((pDirEntry->d_type) == DT_REG)
		{
			chNewName = (char *)malloc(sizeof(pDirEntry->d_name)*2);
			chOldPath = getFullPathWithFileName(chDirName,pDirEntry->d_name);
			sprintf(chNewName,"%d.txt",count); // creaete new file path
			chNewPath = getFullPathWithFileName(chDirName,chNewName);
			count++;

			ret = rename(chOldPath,chNewPath);
			if(ret != 0)
			{
				printf("[ERROR] Cannot rename %s file\n",pDirEntry->d_name);
			}

			free(chOldPath);
			free(chNewPath);
			free(chNewName);
		}
	}

	printf("[INFO] Rename operation done.\n");

	closedir(pDir);

	return(0);
}

/*
 * Function Definition To get file path with folder
 */
char* getFullPathWithFileName(char *chInBasePath,char *chInFileName)
{
	char *retFilePath = (char *)malloc(sizeof(chInBasePath)+sizeof(chInFileName)+1);

	sprintf(retFilePath,"%s",chInBasePath); // concat directory name
	
	//check if last character is '/'
	if((chInBasePath[strlen(chInBasePath)-1]) != '/')
	{
		strcat(retFilePath,"/");
	}

	strcat(retFilePath,chInFileName); // concat file name

	return(retFilePath);
}