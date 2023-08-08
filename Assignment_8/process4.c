#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>

int main()
{
	pid_t pid2=fork();
	if(pid2 ==0)
	{
		printf("process 2 is (PID : %d)\n",getpid());
		printf("process 2 is (PID : %d) treminted \n",getpid());
		return 0;
	}
        else if(pid2 > 0)
	{
		pid_t pid3=fork();
		if(pid3==0)
		{
			printf("process 3 is (PID :%d)\n",getpid());
			printf("process 3 is (PID :%d) treminted \n",getpid());
			return 0;
		}
		else if(pid3>0)
		{
			int status;
			waitpid(pid2,&status,0);
			waitpid(pid3,&status,0);
			printf("parent process terminted (PID %d)\n",getpid());
			return 0;
		}

		else
		{
			printf("process 3 filed\n");
			return 1;
		}
	}
	else
	{
		printf("prcess 2 failed \n");
		return 1;
	}
	return 0;
}
