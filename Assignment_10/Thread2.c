#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
void *ThreadProc1(void *ptr)
{
	int i=0;
	for(int i=0;i<=500;i++)
	{
	printf("Thread 1 is :%d\n",i);
	}
}
void *ThreadProc2(void *ptr)
{
	int i=0;
	for(int i=500;i>=1;i--)
	{
	printf("Thread 2 is :%d\n",i);
	}
}
int main()
{
        pthread_t td1,td2;
	int ret1,ret2=0;
	ret1=pthread_create(&td1,
			NULL,
			ThreadProc1,
			NULL);
	if(ret1!=0)
	{
		printf("unable to create thread \n");
		return -1;
	}
        printf("thread is create is %ld\n",td1);  
	ret2=pthread_create(&td2,
			NULL,
			ThreadProc2,
			NULL);
	if(ret2!=0)
	{
		printf("unable to create thread \n");
		return -1;
	}
        printf("thread is create is %ld\n",td2);  
	pthread_join(td1,NULL);
        pthread_join(td2,NULL);
	return 0;
}

