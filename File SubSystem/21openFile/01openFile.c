#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>

int main(int argc, char **argv)
{
	int fd = 0;
	char *fileName = NULL;

	if(argc != 2)
	{
		printf("[ERROR] Insufficient Arguments");
		return(-1);
	}

	fileName = malloc(strlen(argv[1]));
	fileName = argv[1];

	fd = open(fileName,O_RDONLY);
	if(fd == -1)
	{
		printf("[ERROR] Unable to open file.");
		return(-1);
	}

	printf("[INFO] File open success,file discriptr : %d\n",fd);
	close(fd);

	return(0);
}