#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char **argv)
{
	int fd = 0;
	int mode = 0;
	char *fileName = NULL;

	if(argc != 3)
	{
		printf("[ERROR] Insufficient Arguments\n");
		return(-1);
	}

	//argument to string
	fileName = malloc(strlen(argv[1]));
	fileName = argv[1];
    
    //compare second argument : opening mode
    if((strcmp(argv[2],"O_RDONLY") == 0))
    {
    	mode = O_RDONLY;
    }
    else if((strcmp(argv[2],"O_WRONLY") == 0))
    {
    	mode = O_WRONLY;
    }
    else if((strcmp(argv[2],"O_RDWR") == 0))
    {
    	mode = O_RDWR;
    }
    else if((strcmp(argv[2],"O_APPEND") == 0))
    {
    	mode = O_APPEND;
    }
    else if((strcmp(argv[2],"O_CREAT") == 0))
    {
    	mode = O_RDWR;
    }
    else{
		mode = O_RDONLY;
    }

    //open system call
    fd = open(fileName,mode);

	if(fd == -1)
	{
		printf("[ERROR] Unable to open file in %s mode\n",argv[2]);
		return(-1);
	}

	printf("[INFO] File opened(fd = %d) successfully in %s mode\n", fd, argv[2]);
	close(fd);
    free(fileName);

	return(0);
}