#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>

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
			printf("%s\n", (*psDirInfo).d_name);
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