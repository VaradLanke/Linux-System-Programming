/*
A5_02 : Program which accepts file name from user 
		which contains information of employee 
		and reads all contents of that file.
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
	char *chFileName = NULL;

	if(argc != 2)
	{
		printf("[ERROR] Insufficient arguments\n");
		return(-1);
	}

	//argument processing
	chFileName = argv[1];

	//open result file
	iFd = open(chFileName,O_RDONLY,0644);
	if(iFd == -1)
	{
		printf("[ERROR] Unable to open file\n");
		return(-1);
	}

	//write data into file
	while((iRet = read(iFd,(char *)&sEmp,4096)) != 0)
	{
	}
	printf("[INFO] Name: %s\n", sEmp.chEmpName);
	// iRet = read(iFd,&sEmp.chSalary,sizeof(sEmp.chSalary));
	printf("[INFO] Salary: %s\n", sEmp.chSalary);
	// iRet = read(iFd,&sEmp.chEmpId,sizeof(sEmp.chEmpId));
	printf("[INFO] Id: %s\n", sEmp.chEmpId);


	//close resources
	close(iFd);

	return(0);
}