/*
A4_02 : Program which accepts directory name from user 
		and creates new directory of that name.
*/
#include<stdio.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc,char **argv)
{
	//variable initialization
	int iRet = -2;
	char *chDirName = NULL;
	DIR *pDir = NULL;
	struct dirent *psEntry = NULL;

	//argument validation
	if(argc != 2)
	{
		printf("[ERROR] Insufficient Arguments\n");
		return(-1);
	}

	//argument processing
	chDirName = argv[1];

	//open directory
	pDir = opendir(".");

	if(pDir)
	{
		printf("[INFO] Reading Directory\n");
		while((psEntry = readdir(pDir)) != NULL)
		{
			if((psEntry->d_type == DT_DIR) && (strcmp(psEntry->d_name,chDirName) == 0))
			{
				printf("[ERROR] Directory already exists, cannot create directory\n");
				closedir(pDir);
				return(-1);
			}
		}

		// good to make directory
		iRet = mkdir(chDirName,0777);
		if(iRet == 0)
		{
			printf("[INFO] Directory Created Successfully\n");
		}
		else
		{
			printf("[ERROR] Directory cannot be created\n");
			closedir(pDir);
			return(-1);
		}					

	}
	else
	{
		printf("[ERROR] cannot open directory\n");
	}

	closedir(pDir);

	return(0);
}