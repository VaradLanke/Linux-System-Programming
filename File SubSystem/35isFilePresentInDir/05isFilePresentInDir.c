#include<stdio.h>
#include<string.h>
#include<dirent.h>	//for opendir(),readdir()

int main(int argc,char **argv)
{
	//variable declaration
	char *chFolderName = NULL;
	char *chFileName = NULL;
	DIR *pDir = NULL;
	struct dirent *psDirInfo = NULL;
	int iFoundFlag = 0;

	//argument validation
	if(argc != 3)
	{
		printf("[ERROR] Insufficient arguments\n");
		return(-1);
	}

	//argument processing
	chFolderName = argv[1];
	chFileName = argv[2];

	//open directory
	pDir = opendir(chFolderName);

	if(pDir == NULL)
	{
		printf("[ERROR] Unable to open Directory : %s\n", chFolderName);
		return(-1);
	}

	//read directory content
	while((psDirInfo = readdir(pDir)) != NULL)
	{
		if( strcmp((*psDirInfo).d_name,chFileName) == 0 )
		{
			iFoundFlag = 1;
		}
	}

	if(iFoundFlag == 1)
	{
		printf("[INFO] File Exists in given Folder %s : %s\n",chFolderName,chFileName);
	}
	else
	{
		printf("[INFO] File Not Found in given directory\n");
	}

	//close resources
	closedir(pDir);

	return(0);
}