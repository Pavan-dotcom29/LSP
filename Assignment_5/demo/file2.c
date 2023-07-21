#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
struct employee
{
	char name[20];
	int id;
	int salary;
};
int main(int argc,char *argv[])
{
struct employee eobj;
char fname[20];
int fd=0;
printf("enter thr file name\n");	
scanf("%s",fname);
fd=open(fname,O_RDONLY);
read(fd,&eobj,sizeof(eobj));
printf("employee name is %s\n",eobj.name);
printf("employee id is %d\n",eobj.id);
printf("employee salary is %d\n",eobj.salary);
close(fd);
return 0;
}

