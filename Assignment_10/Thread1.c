#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
void * ThreadProc(void *ptr)
{
	printf("Inside Simple Thread created \n");
}
int main()
{
        pthread_t td1;
	int ret=0;
	ret=pthread_create(&td1,
			NULL,
			ThreadProc,
			NULL);
	if(ret!=0)
	{
		printf("unable to create thread \n");
		return -1;
	}
        printf("thread is create is %ld\n",td1);  
	return 0;
}

