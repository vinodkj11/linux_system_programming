#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main(void)
{
	pid_t pid;
	pid=fork();
	if (pid==0)
	{
	  printf("Childs Parent process ID1 : %d\n",getppid());
	  sleep(10);
	  printf("I am a child process\n");
	  printf("Child process ID : %d \n", getpid());
	  printf("Childs Parent process ID : %d\n",getppid());
	}  
	else
        {
	  printf("I am a parent process\n");
	  printf("Parent process ID : %d \n",getpid());
	  printf("Parent's parent ID(Shell id) : %d\n",getppid());
 	}
	return 0;
}
