/*
	Program to create shared memory and write data into it.
*/
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<unistd.h>

#define SHMSZ 27

int main(int argc, char const *argv[])
{
	
	char c;
	int shmid;
	key_t key;
	char *shm,*s;

	key = ftok(".",1);

	if((shmid = shmget(key,SHMSZ,IPC_CREAT | 0666)) == -1)
	{
		printf("<ERROR> Cannot create shared memory\n");
	}

	printf("<SERVER> Shared memory gets allocated : Id- %d\n",shmid);

	shm = shmat(shmid,NULL,0);

	printf("<SERVER> Shared memory gets attached : %p\n",shm);

	s = shm;

	for(c='a';c<='z';c++)
	{
		*s = c;
		s++;	
	}
	*s = NULL;

	printf("<SERVER> Data gets written in shared memory\n");

	while(*shm != '*')
	{
		//printf("<SERVER> In Waiting state...\n");
		//sleep(1);
	}

	printf("<SERVER> Terminates\n");

	exit(0);
}
