#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int i = 0;
int gData = 10;

void doSomething(char *name)
{
	for(; i< 5 ; i++)
	{
		sleep(rand()%4);
//		printf("i : %d &i = %p  process : %s\n",i, &i, name);
	}
}

int main(void)
{
	pid_t pid = -1;

	printf("I am in process : %u and my ppid: %u\n",getpid(), getppid());
	pid = fork();
	srand((int)pid);

	//	printf("%d %p\n",gData, &gData);
	if(pid < 0)
	{
		printf("fork failed\n");
		return 0;
	}

	if(pid == 0){
		printf("I am child and my pid: %u\n", getpid());
		doSomething("child");
		printf("Child : %d %p\n",gData, &gData);
		printf("I am child and exiting now\n");
	//	exit(5);
	}
	else{

		printf("I am parent and my pid: %u\n", getpid());
		gData = 30;	
		printf("Parent: %d %p\n",gData, &gData);
		doSomething("parent");
		printf("I am parent and waiting for child to finish\n");
		int status = -1;
		pid_t cPid = wait(&status);
		printf("I am parent and exiting now  pid : %u  status : %d\n", cPid, status);

		int wExitStatus = WEXITSTATUS(status);
		printf("Wait Exit Status : %d\n",wExitStatus);	
	}
	return 0;
}

