#include<stdio.h>
#include<string.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

int isCapChar(char);

int main(int argc, char const *argv[])
{
	//variable initialization
	int iFd1 = 0, iFd2 = 0;
	char buffer[512];
	char *chOutput = NULL;
	int iCapCount = 0;
	int ret = 0;

	//argument validation
	if(argc != 2)
	{
		printf("[INFO] Insufficient arguments\n");
		return(-1);
	}

	//open input file
	iFd1 = open(argv[1],O_RDONLY);
	if(iFd1 == -1)
	{
		printf("[ERROR] Cannot open %s file\n",argv[1]);
		return(-1);
	}

	//read contents
	while((ret=read(iFd1,buffer,sizeof(char))) != 0)
	{
		if(ret == -1)
		{
			printf("[ERROR] cannot read file contents\n");
			close(iFd1);
		}

		if((isCapChar(buffer[0])) == 1)
		{
			iCapCount++;
		}
	}

	//open result file for counts
	iFd2 = open("count.txt",O_APPEND | O_CREAT | O_WRONLY,0644);
	if(iFd2 == -1)
	{
		printf("[ERROR] Cannot open count.txt file\n");
		close(iFd1);
		return(-1);
	}

	//print output on console
	chOutput = (char *)malloc(sizeof(char)*512);
	sprintf(chOutput,"(pid:%d) %s:%d\n",getpid(),argv[1],iCapCount);
	printf("[INFO] %s : CapCount: %d\n",argv[1],iCapCount);

	//write output into file
	ret = write(iFd2,chOutput,sizeof(chOutput)*3);
	if(ret == -1)
	{
		printf("[ERROR] Cannot write into count.txt\n");
		close(iFd1);
		close(iFd2);
		free(chOutput);
		return(-1);
	}
	printf("[INFO] written data: %d\n",ret);

	//close resources
	close(iFd1);
	close(iFd2);
	free(chOutput);

	return(0);
}

int isCapChar(char ch)
{
	//65 - 90 ascii value for capital letters
	if(ch>=65 && ch <=90)
	{
		return(1);
	}
	
	return(0);
}