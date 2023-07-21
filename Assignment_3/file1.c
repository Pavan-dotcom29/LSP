//write a program which accept two file names from user and copy the content of an existing file into newly created file.

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<dirent.h>
#include<fcntl.h>
#define BLOCKSIZE 1024
int main()
{
        char filename1[20];
        char filename2[20];
	char buffer[BLOCKSIZE]={'\0'};
	int n=0;
	int fd,fd2=0;
	int ret=0;
	printf("enter the file name 1\n");
	scanf("%s",filename1);
	printf("enter the file name 2\n");
	scanf("%s",filename2);
	fd=open(filename1,O_RDONLY);
        fd2=creat(filename2,O_WRONLY);
	while((ret=read(fd,buffer,sizeof(buffer)))!=0)
	{
		printf("info about \n",ret);
		write(fd2,buffer,ret);
	}
	close(fd);
	close(fd2);
 	return 0;
}
