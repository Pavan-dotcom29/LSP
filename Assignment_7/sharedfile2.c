#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
	struct stat obj1,obj2;
        char buffer1[1024];
        char buffer2[1024];
	int fd1,fd2,ret=0;
	fd1=open(argv[1],O_RDONLY);
	fd2=open(argv[1],O_RDONLY);


	if (fd1 ==-1 || fd2 ==-1)
	{
		printf("unbale to open file \n");
		return -1;
	}
           
         fstat(fd1,&obj1);
         fstat(fd2,&obj2);

	 if(obj1.st_size!=obj2.st_size)
	 {
		 printf("sizes are differnt \n");
		 return -1;
	 }

	 while((ret=read(fd1,buffer1,sizeof(buffer1)))!=0)
	 {
             ret=read(fd2,buffer2,sizeof(buffer2));
	     if(memcmp(buffer1,buffer2,ret))
	     {
		     break;
	     }
	 }
	 if(ret=0)
	 {
		 printf("both file is same\n");
	 }
	 else
	 {

		 printf("both file are differnt \n");
	 }
	 close(fd1);
	 close(fd2);


	return 0;
}
