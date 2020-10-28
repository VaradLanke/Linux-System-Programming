/*
	A8_01 : Program that writes all file names which are present 
			on desktop in demo.txt file
*/
#include<stdio.h>
#include<stdlib.h>
#include<dirent.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char const *argv[])
{
	//variable initialization
	int iFd = 0;
	DIR *pDir = 0;
	struct dirent *dirEntry = NULL;
	char *buffer = NULL;

	pDir = opendir("/home/varad/Desktop");
	if(pDir == NULL)
	{
		printf("[ERROR] Cannot open Desktop Directory.\n");
		return(-1);
	}

	printf("[INFO] Desktop Directory Opened Sucessfully.\n");

	//open new file
	iFd = open("./data.txt",O_APPEND | O_CREAT | O_WRONLY,0644);
	if(iFd == -1)
	{
		printf("[ERROR] Cannot open data.txt file\n");
		closedir(pDir);
		return(-1);
	}

	while((dirEntry = readdir(pDir)) != NULL)
	{
		buffer = (char *)malloc(sizeof(char));
		strcpy(buffer,dirEntry->d_name);
		// printf("[INFO] %s ",buffer);

		write(iFd,buffer,sizeof(buffer));
		write(iFd,"\n",2);

		free(buffer);
	}

	printf("[INFO] All Desktop Entries copied into data.txt sucessfully\n");

	//close resources
	close(iFd);
	closedir(pDir);

	return(0);
}