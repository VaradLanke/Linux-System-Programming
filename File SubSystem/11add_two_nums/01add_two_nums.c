/*
    A1_01 : Program which is used to add two numbers.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char** argv)
{
    //variables initialization
    int number1 = 0;
    int number2 = 0;
    int addition = 0;

    //argument validation
    if(argc != 3)
    {
        //command usage
        if(argc !=1 && ((strcmp(argv[1],"-h")) == 0 || (strcmp(argv[1],"-H")) == 0))
        {
            printf("[USAGE] ./Executable_Name IntegerValue1 IntegerValue2\n");
            return(0);
        }

        printf("[ERROR] Arguments missing.\n");
        return(-1);
    }

    //convert commandline string arguments to integer
    number1 = strtol(argv[1],NULL,10); //prototype: long strtol(const char *restrict str, char **restrict endptr, int base);
    number2 = strtol(argv[2],NULL,10); // strtol() is equivalent to atoi()

    //logic : addition
    addition = number1 + number2;

    //print result
    printf("[SUCCESS] Addition of %d and %d is %d\n",number1,number2,addition);

    return(0);
}