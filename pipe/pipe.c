#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>

int main(void)
{
	pid_t pid = -1;
	int fd[2];
	int ret = pipe(fd);
	     
	pid = fork();
	
	if(pid == 0)
	{
		close(fd[0]);
		char str[]="abcd";
		printf("This is child process and ID: %d\n", getpid());
		printf("Started writing to a pipe\n");
		write(fd[1], str, sizeof(str));
		write(fd[1], "xyz", sizeof(str));
		write(fd[1], "abc123456", 13);
		close(fd[1]);
		printf("End of writing into a pipe\n");
	}
	else{
		close(fd[1]);
		char str[15];
		printf("This is parent process and ID: %d\n", getpid());
		printf("Started reading from pipe\n");
		sleep(2);
		read(fd[0], str, 5);
		printf("Received string : %s\n", str);
		read(fd[0], str, 5);
		printf("Received string : %s\n", str);
		read(fd[0], str, 15);
		printf("Received string : %s\n", str);
		close(fd[0]);
		printf("End of reading from pipe\n");
	}

	return 0;
}
