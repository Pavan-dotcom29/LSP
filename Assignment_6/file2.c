#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#include<dirent.h>
#include<sys/dir.h>


int main(int argc,char *argv[])
{
     DIR *dp=NULL;
struct dirent *entry=NULL;
    printf("<NAME OF EXE> <DIRECTORY NAME> <FILE NAME> \n");
    dp=opendir(argv[1]);     
    if(dp ==NULL)
{
      printf("unable to open directory \n ");
      return -1;
}
   while((entry=readdir(dp))!=NULL)

{
if ((strcmp(argv[2],entry->d_name))==0)
{
printf("file is present in that directory \n");
break;
}

}


if (entry ==NULL)
{
printf("no such file \n");
return -1;
}
closedir(dp);
return 0;

}
