#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>

int main()
{
	pid_t pid=fork();
	
        if(pid < 0)
	{
		printf("fork failed \n");
		exit(EXIT_FAILURE);
	}

	else if(pid==0)
	{
		printf("child procees id running \n");
		sleep(5);
		printf("child process is done \n");
		exit(EXIT_SUCCESS);
	}
	else
	{
		printf("parent process is waiting for the child to treminate \n");
		int status;
		wait(&status);
		if (WIFEXITED(status))
		{
			int exitstatus=WEXITSTATUS(status);
			printf("Child process terminated with exit status: %d\n", exitstatus);
                }
	       	else
	              {
                       printf("Child process terminated abnormally.\n");
                      }
		      printf("parent process is done\n");
	}
	return 0;
}


