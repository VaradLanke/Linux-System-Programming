/*
    A8_07 : Program which is used to pring home directory 
            and login user name.
*/
#include<stdio.h>
#include<string.h>

// global declaration
//extern char **pEnviron;

int main(int argc, char *argv[], char **environ)
{
    char **pEnv = environ;
    int iCount = 0;
    printf("[INFO] Enviornment variables are : \n");
    
    for(;*pEnv!= NULL; ++pEnv)
    {
        //printf("[INFO] %d. %s\n",iCount++,*pEnv);
        if(*pEnv[0]=='H')
        {
            printf("________________________________\n");
            printf("[INFO] %d. %s\n",iCount++,*pEnv);
        }
        else if(*pEnv[0] == 'U')
        {
            printf("________________________________\n");
            printf("[INFO] %d. %s\n",iCount++,*pEnv);
        }
    }
    
    return(0);
}