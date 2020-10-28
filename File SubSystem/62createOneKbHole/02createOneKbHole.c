#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc,char **argv)
{
    int iFd = 0;
    char chInsertValues[4096];

    //argument validation
    if (argc != 2) {
        printf("[ERROR] Insufficient Arguments\n");
        return(-1);
    }

    //open file
    iFd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    if (iFd == -1) {
        printf("[ERROR] Unable to open the file\n");
        return(-1);
    }

    write(iFd, chInsertValues, 4096);
    lseek(iFd, 10 * 100, SEEK_CUR);
    write(iFd, chInsertValues, 4096);

    //close resources
    close(iFd);

    return(0);
}