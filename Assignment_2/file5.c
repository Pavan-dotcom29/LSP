#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<dirent.h>




int main()
{
	DIR *dp=NULL;
	struct dirent *entry=NULL;
	char name[20];
	char dirname[20];
	int imax=0;
	char namecopy[20];
	struct stat sobj;
	printf("enter the name of directory that you want to open \n");
	scanf("%s",dirname);


        dp = opendir(dirname);
         if(dp == NULL)
         {
            printf("Unable to open directory\n");
            return -1;
         }
	 else
	 {
		 printf("the directory name is :%s\n",dirname);
	 }



	 while((entry=readdir(dp))!=NULL)
	 {

		if ( imax < sobj.st_size)
		{
			imax=sobj.st_size;
			strcpy(namecopy,name);

		}	
		 printf("name of largest file: %s with size %d bytes \n",namecopy,imax);

	 }


	 closedir(dp);
	 return 0;
         
         	 
}

