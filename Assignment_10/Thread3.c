#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
void *ThreadProc(void *ptr)
{
        int i=(int)ptr;
	printf("value reurned is from main thread is %d\n",(int)ptr);
	pthread_exit(++i);
}
int main()
{
        pthread_t td;
	int ret=0;
	int no=17;
	int value=0;
	ret=pthread_create(&td,
			NULL,
			ThreadProc,
			(int *)no);
	if(ret!=0)
	{
		printf("unable to create thread \n");
		return -1;
	}
        printf("thread is create is %ld\n",td);  
	pthread_join(td,&value);
        printf("return value from thread is  %ld\n",value);  

	return 0;
}

