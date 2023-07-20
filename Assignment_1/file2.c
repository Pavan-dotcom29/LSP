//write a program which accept file ane and mode from user and then open that file in specified mode.

#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
	int fd=0;
	char fname[20];
	char smode[10];
	int mode=0;
	printf("Enter the <NAME FILE> and <MODE> that you want open\n");
        printf("enter the file name that you want to open\n");	
	scanf("%s",fname);
	printf("which mode you want to open <O_RDONLY,O_RWONLY> \n");
	scanf("%s",smode);



	return 0;
}
