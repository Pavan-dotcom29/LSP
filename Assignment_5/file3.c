#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
	DIR *dp=NULL;
	struct dirent *entry=NULL;	
	char dirname[20];
	char name[20];
	struct stat sobj;
	printf("enter the directory name\n");
	scanf("%s",dirname);
	dp=opendir(dirname);
	if (dp == NULL)
	{
          printf("unable to oprn directory\n");
	  return -1;
	}
             while((entry=readdir(dp))!=NULL)
	     {
		     sprintf(name,"%s/%s",dirname,entry->d_name);
		     stat(name,&sobj);
		     if(S_ISREG(sobj.st_mode))
		     {
			     printf("file name is %s file size id %ld\n",name,sobj.st_size);
		     }
	     }
		     closedir(dp);
		     return 0;
}

