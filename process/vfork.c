#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	pid_t pid;
	pid=vfork();
    if (pid==0)
	{
		printf("I am a child process\n");
		printf("Child process ID : %d \n", getpid());
	    printf("Child's Parent process ID : %d\n",getppid());
	    execl("./fork",argv[0],NULL);
		_exit(0);
    }  
    else
    {
		printf("I am a parent process\n");
		printf("Parent process ID : %d \n",getpid());
		printf("Parent's parent ID(Shell id) : %d\n",getppid());
 	}
	return 0;
}
