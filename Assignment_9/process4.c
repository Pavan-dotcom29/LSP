#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/resource.h>

int main()
{
	int pr=getpriority(PRIO_PROCESS,0);
	if(pr==-1)
	{
		printf("failed to get procress \n");
		return -1;
	}
        printf("current priority of the process id (PID : %d) is %d\n",getpid() ,pr);

	int new_pr=pr + 5;
	if (setpriority(PRIO_PROCESS,0,new_pr))
	{
		printf("failed to get procress \n");
		return -1;
	}
        printf("new priority of the process id (PID : %d) is %d\n",getpid() ,new_pr);


        int up_pr=getpriority(PRIO_PROCESS,0);
	if(up_pr==-1)
	{
		printf("failed to get procress \n");
		return -1;
	}
        printf("updated priority of the process id (PID : %d) is %d\n",getpid() ,up_pr);
        return 0;

}
