#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>


int main()
{
	int fd=0;
        char fname[20];  
	char *Buffer=NULL;
	int Size=0;
	printf("enter the file name\n");
	scanf("%s",fname);

	fd=open(fname,O_RDONLY);
	read(fd,50,

return 0;
}


