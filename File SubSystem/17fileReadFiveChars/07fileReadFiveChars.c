/*
    A1_07 : Program which accepts file name and reads 
            first 5 characters from it.
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
    int ret = 0;
    int offset = 0;
    char buffer[10];

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

        ret = read(fileDescriptor,buffer,5);
        if(ret != 5)
        {
            printf("[ERROR] Unable to read contents\n");
            close(fileDescriptor);
            return(-1);
        }

        printf("[INFO] Read contents are : \n%s\n",buffer);

        //get bytes uptil current cursor
        offset = lseek(fileDescriptor,0,SEEK_CUR);
        printf("[INFO] After reading 5 bytes offset is : %d\n",offset);

        //close file
        close(fileDescriptor);
    }
    return(0);
}
