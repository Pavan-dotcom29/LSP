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
	char dirname[20];
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
		 printf("%s\n",entry->d_name);

	 }


	 closedir(dp);
	 return 0;
         
         	 
}

