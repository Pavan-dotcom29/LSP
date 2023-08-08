#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
	printf("process 1 (PID is %d) is starting \n",getpid());

	pid_t pid2=fork();
	if (pid2 < 0)
	{
		printf("fork failed\n");
		return 1;
	}

	else if (pid2==0)
	{
		printf("process 2 (PID is %d) is starting:PArent PID :%d\n",getpid(), getpid());

		pid_t pid3=fork();
		if(pid3 < 0)
		{
		 printf("fork failed\n");
		 return 1;
		}
	         else if (pid3==0)
	{
		printf("process 3 (PID is %d) is starting:PArent PID :%d\n",getpid(), getpid());
		printf("process 3 done\n");

	}
		else
		{
			wait(NULL);
			pid_t pid4=fork();
			if (pid4 < 0)
			{
				printf("fork failed\n");
                                return 1;
			}
			else if (pid4 == 0)
			{
				printf("Process 4 (PID: %d) is starting. Parent PID: %d\n", getpid(), getppid());
                                printf("Process 4 is done.\n");
			}
			else
			{
				wait(NULL);
				printf("process2 is done\n");
			}


		}
 }
	else
	{
		wait(NULL);
		printf("process 1 donme \n");
	}
	return 0;
}
