#include<stdio.h>
#include<dirent.h>
#include<sys/stat.h>
#include <sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<libgen.h>

//function declaration
char* getFullPathWithFileName(char[],char[]);
int writeStructIntoFile(char[]);
long readStructFromFile(char[]);

int main(int argc,char **argv)
{
	//variable declaration
	int iFd = 0;
	int iRet = 0;
	char *chInFileName = NULL;
	char *chDirName = NULL;
	char *chFullPathFile = NULL;
	DIR *pDir=NULL;
	struct dirent *entryFile = NULL;

	//argument validation
	if(argc != 2)
	{
		printf("[ERROR] Insufficient Arguments\n");
		return(-1);
	}

	//argument processing
	chInFileName = (char *)malloc(sizeof(char)*strlen(argv[1]));
	chInFileName = strcpy(chInFileName,argv[1]);
	chDirName = dirname(argv[1]);

	// printf("[INFO] Input File: %s\n",chInFileName);
	// printf("[INFO] Dir Name: %s\n",chDirName);

/*	//open directory
	pDir = opendir(chDirName);
	if(pDir)
	{
		//read directory
		while((entryFile = readdir(pDir)) != NULL)
		{
			if(entryFile->d_type != DT_DIR)
			{
				// printf("[INFO] fName: %s\n",entryFile->d_name);
				chFullPathFile = getFullPathWithFileName(chDirName,entryFile->d_name);
				writeStructIntoFile(chFullPathFile);
				free(chFullPathFile);
			}
		}
	}
	else
	{
		printf("[ERROR] Unable to open directory : %s\n",chDirName);
		return(-1);
	}
*/
	//open file containig stat struct
	printf("[INFO] Files greater than 10 bytes are : \n");
	readStructFromFile(chInFileName);

	//close resources
	free(chInFileName);

	return(0);
}

/*
 * Function Definition To get file path with folder
 */
char* getFullPathWithFileName(char chInBasePath[],char chInFileName[])
{
	char *retFilePath = malloc(strlen(chInBasePath)+strlen(chInFileName)+10);

	strcat(retFilePath,chInBasePath); // concat folder name
	
	//check if last character is '/'
	if((chInBasePath[strlen(chInBasePath)-1]) != '/')
	{
		strcat(retFilePath,"/");
	}

	strcat(retFilePath,chInFileName); // concat file name

	return(retFilePath);
}

/*
 * write file properties into one file
 */
int writeStructIntoFile(char chFileName[])
{
	//local variables
	struct stat entry;
	int iRet = -1;
	FILE *outFile = NULL;

	iRet = stat(chFileName,&entry);

	//open dataFile.txt
	outFile = fopen("./test/dataFile.txt","a");

	//write stat struct into it.
	fwrite (&entry, sizeof(struct stat), 1, outFile);
	fclose(outFile);

	return(iRet);
}

/*
 * read file properties from another file
 */
long readStructFromFile(char chFileName[])
{
	//local variables
	struct stat entry;
	int iRet = -1;
	FILE *inFile = NULL;

	//open dataFile.txt
	inFile = fopen(chFileName,"r");

	//read stat struct from it.
	while(fread(&entry,sizeof(struct stat),1,inFile))
	{
		if(entry.st_size > 10)
		{
			printf(" | iNode:%ld\n",entry.st_ino);
		}
	}
	fclose(inFile);

	return(iRet);
}