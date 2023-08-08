#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/resource.h>



int main()
{
	int pr=getpriority(PRIO_PROCESS,0);

	if(pr==-1)
	{
		printf("failed to get prcoess in prriority\n");
		return 1;
	}

	printf("priority of current process is (PID :%d) is %d \n",getpid(),pr);
	return 0;
}
