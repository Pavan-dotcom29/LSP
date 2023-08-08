#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include "sharedfile1.h"

int main()
{ 
	int a=10,b=11,ret=0;

	ret=Addition(a,b);
	printf("Addition is %d\n",ret);

	ret=sub(a,b);
	printf("sub is %d\n",ret);

	ret=mul(a,b);
	printf("mul is %d\n",ret);

	ret=div1(a,b);
	printf("div is %d\n",ret);

	return 0;
}
