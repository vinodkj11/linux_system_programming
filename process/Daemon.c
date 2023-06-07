#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int main(void)
{
	FILE *fp;
	pid_t pid;
	pid_t sid;

	printf("My PID is : %d\n", getpid());

/*	pid = fork();
	if(pid < 0)
	{
		perror("fork failed");
		exit(1);
	}*/
	umask(0); //this will make newly creared dir readable, writable
	sid = setsid();
	if(sid < 0)
	{
		perror("setsid failed");
		exit(1);
	}
	//chdir("./Daemonlog");
	fp = fopen("Daemon_log.txt", "a+");
	if(fp == NULL)
	{
		perror("File creation failed");
		exit(1);
	}
	while(1)
	{
		int ret = fprintf(fp, "Daemon caught this logs\n");
//		perror("fprintf");
		sleep(2);
		fflush(fp);
	}
	//fclose(fp);
	return 0;
}
