/*
    A1_06 : Program which accepts file name from user and 
            opens that file and if file is not opened properly 
            then displays error message properly.
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
    //initialize variables
    char inputFileName[50];
    int fileDescriptor;

    //scan file name
    printf("[INPUT] Enter File Name : ");
    scanf("%s",inputFileName);
    printf("[INFO] FileName : %s\n",inputFileName);

    //open file
    fileDescriptor = open(inputFileName,O_RDONLY);

    //check status of file descriptor
    if(fileDescriptor == -1){
        printf("[ERROR] Unable to open file : %s\n",inputFileName);
        return(-1);
    }
    else
    {
        printf("[INFO] File opened Successfully with fileDescriptor : %d\n", fileDescriptor);
        //close file
        close(fileDescriptor);
    }
    return(0);
}
