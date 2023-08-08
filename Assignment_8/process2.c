#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
	printf("process 1 (PID : %d ) is starting \n", getpid());

	pid_t pid2=0;
	if(pid2 <0)
	{
		printf("fork error\n");
		return 1;
	}
	else if(pid2 == 0)
	{
		printf("process 2 (PID : %d ) is staring parent PID %d\n",getpid(), getpid());
		pid_t pid3=fork();

		if(pid3 <0)
		{
			printf("fork error\n");
                        return 1;
		}
		else if(pid3==0)
		{
			printf("Process 3 (PID: %d) is starting. Parent PID: %d\n", getpid(), getppid());
                        printf("Process 3 is done.\n");
		}
		else
		{
			wait(NULL);
			printf("process 2 is done \n");
		}

	}
	else
	{
		wait(NULL);
		printf("process 1 is done \n");
	}
	return 0;

}
