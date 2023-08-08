#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>

void displayfileinfo(const char* filename)
{
	struct stat filestat;
	if(stat(filename,&filestat)==-1)
	{
		printf("cannot get file inof\n");
		return ;
	}

	 printf("File Information for '%s':\n", filename);
         printf("File Size: %ld bytes\n", filestat.st_size);
         printf("File Permissions: %o\n", filestat.st_mode & 0777);
         printf("File Inode: %lu\n", filestat.st_ino);
}
