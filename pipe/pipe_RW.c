#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	pid_t pid = -1;
	int fd[2];
	int ret = pipe(fd);
	pid = fork();

	if(pid !=0){
		printf("Writing in Parent Process\n");
		write(fd[1], "adbcd", 6);
		close(fd[1]);
		char str[15];
		printf("This is Parent process and ID: %d\n", getpid());
		printf("Started reading from pipe\n");
		read(fd[0], str, 5);
		printf("Received string : %s\n", str);
		read(fd[0], str, 5);
		printf("Received string : %s\n", str);
		read(fd[0], str, 15);
		printf("Received string : %s\n", str);
		close(fd[0]);
		printf("End of reading from pipe\n");
	}
	else
	{
		char str1[10];
		read(fd[0],str1, 6);
		printf("Reading in Child process %s\n", str1);
		close(fd[0]);
		char str[]="abcd";

		printf("This is Child process and ID: %d\n", getpid());
		printf("Started writing to a pipe\n");
		write(fd[1], str, sizeof(str));
		write(fd[1], "xyz", sizeof(str));
		write(fd[1], "xyzabc123456", 13);
		close(fd[1]);
		printf("End of writing into a pipe\n");
	}

	return 0;
}
