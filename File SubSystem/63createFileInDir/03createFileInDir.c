#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>	//for creat()
#include<sys/stat.h>	//struct stat, stat()
#include<unistd.h>

int main(int argc,const char **argv)
{
	//variable declaration
	int iFd = 0;
	char *chDirName = NULL;
	char *chFileName = NULL;
	char *chFullPath = NULL;
	struct stat fileInfo;

	if(argc != 3)
	{
		printf("[ERROR] Insufficient Arguments\n");
		return(-1);
	}

	//argument processing
	chDirName = (char *)malloc(sizeof(char)*strlen(argv[1]));
	chFileName = (char *)malloc(sizeof(char)*strlen(argv[2]));
	chFullPath = (char *)malloc(sizeof(char)*strlen(argv[1])+strlen(argv[2])+1);
	chDirName = strcpy(chDirName,argv[1]);
	chFileName = strcpy(chFileName,argv[2]);

	//create full path of file
	strcat(chFullPath,chDirName);
	strcat(chFullPath,"/");
	strcat(chFullPath,chFileName);

	// printf("[INFO] Dir: %s\n",chDirName);
	// printf("[INFO] File: %s\n",chFileName);
	// printf("[INFO] Path: %s\n",chFullPath);

	if(stat(chDirName,&fileInfo) == -1)
	{
		mkdir(chDirName,0700);
	}

	//create file inside given directory
	iFd = creat(chFullPath,0644);
	if(iFd == -1)
	{
		printf("[ERROR] Unable to create file: %s\n",chFullPath);
		return(-1);
	}

	printf("[INFO] File Created Successfully : %s\n",chFullPath);

	//close resources
	close(iFd);
	free(chDirName);
	free(chFileName);
	free(chFullPath);

	return(0);
}