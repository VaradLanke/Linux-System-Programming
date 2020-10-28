/*
    A1_08 : Program which accepts filename and string from user
            and writes that string into file.
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc,char **argv)
{
	char inputFileName[50];
	int fileDescriptor = 0;
	int ret = 0;
	int offset = 0;
	char buff[10];

    //scan file name
    printf("[INPUT] Enter File Name : ");
    scanf("%s",inputFileName);
    printf("[INFO] FileName : %s\n",inputFileName);

    //open file
    fileDescriptor = open(inputFileName,O_RDONLY);

    //check status of file descriptor
    if(fileDescriptor == -1)
    {
        printf("[ERROR] Unable to open file : %s\n",inputFileName);
        return(-1);
    }

    printf("[INFO] File opened Successfully with fileDescriptor : %d\n", fileDescriptor);

    //ret = read(fileDescriptor,buff,1024);
    /*if(ret != 1024)
    {
    	printf("[ERROR] Unable tp read contents of file");
    	return(-1);
    }*/
    while((read(fileDescriptor,buff,1024))){
    	printf("[INFO] File Content : %s\n",buff);
    }

    return(0);
}