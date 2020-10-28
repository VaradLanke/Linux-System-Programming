/*
A5_01 : Program which writes structure in file 
		which contains information of Employee.
*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

struct Employee
{
	char *chEmpId;
	char *chSalary;
	char *chEmpName;
};

int main(int argc, char** argv)
{
	//variable initialization
	int iFd = 0;
	int iRet = 0;
	struct Employee sEmp = {0};

	if(argc != 4)
	{
		printf("[ERROR] Insufficient arguments\n");
		return(-1);
	}

	//argument processing
	sEmp.chEmpId = argv[1];
	sEmp.chEmpName = argv[2];
	sEmp.chSalary = argv[3];

	//open result file
	iFd = open("./data.txt",O_CREAT|O_WRONLY,0644);
	if(iFd == -1)
	{
		printf("[ERROR] Unable to open file\n");
		return(-1);
	}

	//write data into file
	iRet = write(iFd,(char *)&sEmp,sizeof(sEmp));
	if(iRet == -1)
	{
		printf("[ERROR] Cannot write into file\n");
		close(iFd);
		return(-1);
	}

	//close resources
	close(iFd);

	return(0);
}