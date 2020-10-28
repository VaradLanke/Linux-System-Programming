#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char **argv)
{

	printf("<INFO> Addition process executing (pid: %d)\n",getpid());

	//argument validation
    if(argc != 3)
    {
        //command usage
        printf("[ERROR] Arguments missing.\n");
        printf("[USAGE] ./Executable_Name IntegerValue1 IntegerValue2\n");
        return(-1);
    }

	//variable initialization
	int num1 = strtol(argv[1],NULL,10);
	int num2 = strtol(argv[2],NULL,10);
	int result = 0;

	result = num1 + num2;

	printf("[INFO] Addition of %d and %d is %d\n",num1,num2,result);

	return(0);
}
