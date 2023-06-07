#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	pid_t pid1, pid2;
	pid1 = fork();
	
	if (pid1 == 0)
	{
//		int *ptr=NULL;
		printf("I am a child process--pid1\n");
		printf("child process ID --pid1: %d \n", getpid());
		printf("Child's Parent process ID --pid1 : %d \n",getppid());
//		*ptr = 10;
		printf("Done\n");
		exit(0);
	} 
	pid2 = fork();
	if (pid2 == 0)
	{
		int *ptr=NULL;
		printf("I am a child process --pid2\n");
		printf("child process ID --pid2: %d \n", getpid());
		printf("Child's Parent process ID --pid2 : %d \n",getppid());
		*ptr = 10;
		exit(0);
	}
	else
	{
		int status = -1;
		pid_t cpid = -1;
		printf("Parent Process : %d\n",getpid());
		cpid = waitpid(pid2,&status,0);
		printf("Child Id is %d and status is  %d\n",cpid,status);
		if ( (status & 0xff) != 0)
			printf("Process Terminated Abnormally\n"); 
		else
			printf("Process Terminated Normally\n");
	}
	return 0;
}
