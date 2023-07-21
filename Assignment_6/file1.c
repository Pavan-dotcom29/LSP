#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>



int main(int argc,char *argv[])
{
	DIR *dp=NULL;
	char dirname[20];
	struct dirent *entry=NULL;
	struct stat sobj;
	char name[20];
	char namecopy[20];
	int imax=10;
	printf("enter the directoty name: \n");
	scanf("%s",dirname);


	dp=opendir(dirname);
	if(dp==NULL)
	{
		printf("unable to open directory \n");
		return 0;
	}

	while((entry=readdir(dp))!=NULL)
	{
		//printf("directory name %s and file is %s \n ",dirname,entry->d_name); 
		stat(name,&sobj);
		if(S_ISREG(sobj.st_size))
		{
			if(imax < sobj.st_size)
			{
				imax=sobj.st_size;
				strcpy(namecopy,name);
			}

		}
	}


	printf("file name is %s  which is greater then 10 bytes \n",namecopy,imax); 
	closedir(dp);


        return 0;

}
