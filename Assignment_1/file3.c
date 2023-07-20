//write a program whcih accept file name from user and print all inforamtion ablout file.


#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main()
{
	int fd=0;
	
	printf("Enter <NAME OF FILE>\n");
	if (argc=!2 )
	{
		printf("invalid arguments \n");
		return -1;
	}


	fd=open(argv[1],O_RDONLY);
	if(fd==NULL)
	{
		printf("unable to open a file\n");
		return -1;
	}
        
	else
		while((d=read(fd)!=NULL))
			printf("%s",d);
	close(fd);
	return 0;



}
