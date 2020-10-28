/*
    A8_06 : Program which is used to display Environment of our running process.
*/
#include<stdio.h>

// global declaration
//extern char **pEnviron;

int main(int argc, char *argv[], char **environ)
{
    char **pEnv = environ;
    int iCount = 0;
    printf("[INFO] Enviornment variables are : \n");
    
    for(;*pEnv!= NULL; ++pEnv)
    {
        printf("________________________________\n");
        printf("[INFO] %d. %s\n",iCount++,*pEnv);
    }
    
    return(0);
}