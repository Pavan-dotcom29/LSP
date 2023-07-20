//write a program which accept the file name from user and open that file.


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    int fd=0;
    char fname[20];
    printf("enter the file that you want to open \n");
    scanf("%s",fname);

    fd=open(fname,O_RDONLY);
    if(fd == -1)
    {
	    printf("unable to open a file \n");
	    return -1;
    }

    else
    {
	    printf("file is open at fd %d",fd);

    }
    return 0;
}
