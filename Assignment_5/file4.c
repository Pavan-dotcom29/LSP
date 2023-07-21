#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<dirent.h>
#include<sys/stat.h>
#pragma pack(1)
struct fileinfo
{
	char filename[20];
	int filesize;
};

int main(int argc,char *argv[])
{
      char dirname[20];
      DIR *dp=NULL;
      int fd=0;
      struct dirent *entry =NULL;
      struct stat sobj;
      struct fileinfo fobj;
      char name[20];
      printf("enter the directoty name \n");	
      scanf("%s",dirname);


      dp=opendir(dirname);
      if(dp==NULL)
      {
	      printf("unable to open directory \n");
	      return -1;
      }

      fd=creat("combine.txt",0777);

      while((entry=readdir(dp))!=NULL)
      {
	      sprintf(name,"%s/%s",dirname,entry->d_name);
	      stat(name,&sobj);
	      if(S_ISREG(sobj.st_size))
	      {
                 fobj.filesize=sobj.st_size;
		 strcpy(fobj.filesize,entry->d_name);
		 write(fd,&fobj,sizeof(fobj));
		 printf("%s\n",entry->d_name);
	      }
      }
      closedir(dp);
      return 0;
}
