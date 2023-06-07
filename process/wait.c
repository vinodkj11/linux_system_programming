#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	pid_t pid;
	pid = fork();
	if (pid == 0)
	{
		int *ptr=NULL;
		printf("I am a child process\n");
		printf("child process ID : %d \n", getpid());
		printf("Child's Parent process ID : %d \n",getppid());
		*ptr = 10;
		exit(0);
	}
	else
	{
		int status = -1;
		pid_t cpid = -1;
		printf("Parent Process\n");
		cpid = wait(&status);
		printf("Child Id is %d and status is  %d\n",cpid,status);
		if ( (status & 0xff) != 0)
			printf("Process Terminated Abnormally\n"); 
		else
			printf("Process Terminated Normally\n");
	}
	getchar();
}
