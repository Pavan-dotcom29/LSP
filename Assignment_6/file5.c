#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc,char *argv[])
{
	char fname[50];
	long off=0;
	printf("enter the file anme \n");
	scanf("%s",fname);

	printf("enter the offset \n");
	scanf("%ld",&off);

int fd=0;
	fd=open(fname,0777);
	if(fd==0)
	{
		printf("unable to open file \n");
		return -1;
	}


	fseek(fd,off,SEEK_SET);
	printf("data is removed from offset \n",off);
	return 0;


}
































































//int main(int argc,char *argv[])
//{
//         if (argc=!2)
//	 {
//              printf("invliad argumnts \n"); 
//	      return -1;
//	 }
//	 else
//	 {
//		 printf("file is open sucessfully \n");
//	 }
//         int fd=0;
//	 fd=open(argv[1],O_RDONLY);
//	 if (fd==-1)
//	 {
//		 printf("unable to open the file \n");
//		 return -1;
//	 }
//
//
//
//}
//
