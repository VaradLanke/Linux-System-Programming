/*
	A8_04 : Program which is used to print priority of current process.
*/
#include<stdio.h>
#include<unistd.h>

int main(int argc, int **argv)
{
	//variable initialization
    int iRet = 0;
    
    iRet = nice(0);
    printf("Default Priority is : %d\n",iRet);

    /*iRet = nice(10);
    printf("Changed Priority is : %d\n",iRet);
    
    iRet = nice(-17);
    printf("Changed Priority is : %d\n",iRet);*/
    
    return(0);
}
/*
 Nice values / Proority range (-20 to 19)
 
 
 -20 -19  -18  -17  -16  -15  -14  -13  -12  -11  -10  -9  -8   -7  -6   -5  -4   -3   -2  -1   0
 1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19
 
 Highest prority : -20
 Lowest prority : 19
 Default prority : 0
 
 */