/*
	A8_05 : Program which is used to increase the priority by 5.
*/
#include<stdio.h>
#include<unistd.h>

int main(int argc, int **argv)
{
	//variable initialization
    int iRet = 0;
    
    iRet = nice(0);
    printf("Default Priority is : %d\n",iRet);

    iRet = nice(5);
    printf("Changed Priority is : %d\n",iRet);
    
    return(0);
}