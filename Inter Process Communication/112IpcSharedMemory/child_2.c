/*
	Program to get shared memory and read data from it.
*/
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdlib.h>
#include<unistd.h>

#define SHMSZ 27

int main(int argc, char const *argv[])
{
	
	int shmid;
	key_t key;
	char *shm,*s;

	key = ftok(".",1);

	
	if((shmid = shmget(key,SHMSZ,0666)) == -1)
	{
		printf("<ERROR> Cannot get shared memory\n");
	}

	printf("<CLIENT> Shared memory gets allocated : Id- %d\n",shmid);

	shm = shmat(shmid,NULL,0);

	printf("<CLIENT> Shared memory gets attached : %p\n",shm);

	s = shm;

	for(s = shm;*s != NULL;s++)
	{
		putchar(*s);
	}

	printf(" ");
	printf("\n<CLIENT> Data gets retrieved from shared memory\n");

	*shm = '*';

	printf("<CLIENT> Terminates\n");

	exit(0);
}