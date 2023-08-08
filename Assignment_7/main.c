#include<stdio.h>
#include "fileinfo5.h"

int main()
{
	char filename[500];
	printf("enter thr filename \n");
	scanf("%s",filename);

	displayfileinfo(filename);
	return 0;
}
