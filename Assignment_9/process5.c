#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sched.h>

int main()
{
	printf("starting process \n");

	sched_yield();

	printf("resume process \n");


	return 0;
}
