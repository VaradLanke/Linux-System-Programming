/*
    A1_05 : Program which accepts file name from user and opens that file.
*/
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    //initialize variables
    char inputFileName[50];
    int fileDescriptor;

    //scan filename
    printf("[INPUT] Enter File Name : ");
    scanf("%s",inputFileName);
    printf("[INFO] FileName : %s\n",inputFileName);

    //open file
    fileDescriptor = open(inputFileName,O_RDONLY);

    //print file descriptor status
    printf("[INFO] File status fd : %d\n",fileDescriptor);

    //close file
    close(fileDescriptor);

    return(0);
}