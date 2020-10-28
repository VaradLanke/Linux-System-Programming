/*
    A1_02 : Program which accept name from command line argument
            and display it on screen.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(int argc,char** argv)
{
    //variables initialization
    char *name = NULL;
    int argLength = 0;

    //command validation
    if(argc <= 1)
    {
        printf("[ERROR] Insufficient Arguments\n");
        return(-1);
    }
    
    //command usage
    if(argc != 1 && ((strcmp(argv[1],"-h")) == 0 || (strcmp(argv[1],"-H")) == 0))
    {
        printf("[USAGE] ExecutableName StringArgument1\n");
        return(0);
    }

    //argument to string conversion
    argLength = strlen(argv[1]);
    name = malloc(argLength);
    name[0] = '\0';
    strcat(name,argv[1]);   //prototype : char *strcat(char *destination, const char *source)
    
    //display name on console
    printf("[SUCCESS] Name : %s\n", name);

    free(name);
    return(0);
}