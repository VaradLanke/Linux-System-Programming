#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<time.h>

//Function declaration
void printFileInfo(struct stat,char *);

//Entry point
int main(int argc,char **argv)
{
	//variable initialization
	int fd = 0;
	int mode = 0;
	char *fileName = NULL;
	struct stat fileStats;

	if(argc != 2)
	{
		printf("[ERROR] Insufficient Arguments\n");
		return(-1);
	}

	//Argument to string
	fileName = malloc(strlen(argv[1]));
	fileName = argv[1];

	//check stat sys call status
	if(stat(fileName,&fileStats) == 0)    //prototype : int stat(const char *path, struct stat *buf);
	{
		printFileInfo(fileStats,fileName);
	}
	else
	{
		printf("[ERROR] Unable to fetch File Properties\n");
		printf("[CHECK] Please Check whether %s file exists\n",fileName);
		return(-1);
	}

	free(fileName);
	return(0);
}

/**
 * Function definition to print file properties
 */
void printFileInfo(struct stat fileStats,char *fileName)
{
	struct tm dt;

	printf("%2sFile: %s\n","  ",fileName);

	printf("%2sSize: %ld bytes\t","  ",fileStats.st_size);
	printf("Blocks: %ld\t",fileStats.st_blocks);
	printf("IO Block: %ld\t",fileStats.st_blksize);
	printf("File Type: %ld\n",fileStats.st_rdev);

	printf("Device: %ld\t",fileStats.st_dev);
	printf("\tInode: %ld\t",fileStats.st_ino);
	printf("Links: %ld\n",fileStats.st_nlink);

	printf("Access: %d\t",fileStats.st_mode);
	printf("\tUid: %d\t",fileStats.st_uid);
	printf("Gid: %d\n",fileStats.st_gid);

	dt = *(gmtime(&fileStats.st_atime));
	printf("Access: %d-%d-%d %d:%d:%d\n",dt.tm_mday, dt.tm_mon, dt.tm_year + 1900,
										dt.tm_hour, dt.tm_min, dt.tm_sec);

	dt = *(gmtime(&fileStats.st_mtime));
	printf("Modify: %d-%d-%d %d:%d:%d\n",dt.tm_mday, dt.tm_mon, dt.tm_year + 1900,
										dt.tm_hour, dt.tm_min, dt.tm_sec);

	dt = *(gmtime(&fileStats.st_ctime));
	printf("Change: %d-%d-%d %d:%d:%d\n",dt.tm_mday, dt.tm_mon, dt.tm_year + 1900,
										dt.tm_hour, dt.tm_min, dt.tm_sec);
}