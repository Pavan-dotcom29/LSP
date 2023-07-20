#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    char name[30];
    int fd,n=0;
    char buff[50];
    printf("Enter name of file : \n");
    scanf("%s",name);


    fd=open(name,O_RDONLY);
    if (fd==1)
    {
      printf("unable to open file \n");
      return 0;
    }

     n=read(fd,buff,10);
     write(1,buff,n);

    return 0;


    
}


