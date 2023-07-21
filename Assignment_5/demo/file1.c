#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#pragma pack(1)
struct student 
{
int no;
float marks;
char sname[20];
int age;
};

int main(int argc ,char * argv[])
{
struct student sobj;
char fname[20];
sobj.no=11;
sobj.marks=23.35;
sobj.age=23;
strcpy(sobj.sname,"Pavan");
int fd=0;
printf("enter the file anem \n");
scanf("%s",fname);
fd=creat(fname,0777);
write(fd,&sobj,sizeof(sobj));
return 0;
}



