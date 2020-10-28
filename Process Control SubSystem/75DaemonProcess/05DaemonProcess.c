/*
    A7_05 : Program which is used to create deamon process.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include <sys/stat.h>

int main(int argc,char **argv)
{
    //variables initialization
    int childPid = -1;
    int wsStatus;

    printf("[INFO] Main process : %d\n",getpid());

    //create process
    childPid=fork();

    if(childPid < 0)
    {
        printf("[ERROR] fork() failed!\n");
        return(-1);
        /*case 0: //child process
        printf("<INFO> Child process executing...\n");
        printf("<INFO> Child created sucessfully\n");
        printf("<INFO> Child's Parent pid: %d\n",getppid());
        printf("<INFO> Child Pid: %d\n",getpid());
        break;*/
    }
    if(childPid > 0)
    {
        //parent process
        printf("[INFO] Parent process executing...\n");
        printf("[INFO] PPid: %d\n",getppid());
        printf("[INFO] Pid: %d\n",getpid());
        printf("[INFO] Child Pid(Daemon Process): %d\n",childPid);
        exit(0); // Terminate Parent process
    }

    umask(0);//unmasking the file mode

    int sid = setsid();//set new session
    if(sid < 0)
    {
        exit(1);
    }

    close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    sleep(10);
    printf("[INFO] END\n");
    
    return(0);
}

/*
    Run : ps -A | grep "05DaemonProcess"
    (To see the daemon process)
*/