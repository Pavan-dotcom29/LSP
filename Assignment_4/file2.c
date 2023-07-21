//write a Program which accept directory name from user and create new directory of that name.

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<string.h>
#include<dirent.h>
#include<sys/dir.h>

int main()
{
	char dirname[20];
        int dp=0;
	printf("enter the directory name \n");
	scanf("%s",dirname);
	dp=mkdir(dirname,0777);
	if(dp == 0)
        {
        printf("directory created succesfully\n");
        }
	else
	{
	printf("unable to create %s\n",dirname);
	}
	return 0;
}

