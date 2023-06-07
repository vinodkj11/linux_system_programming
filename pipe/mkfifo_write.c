#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int fd = -1;

	fd = open("./fifo1", O_WRONLY | O_NONBLOCK);
	if(fd > 0)
	{
		write(fd, argv[1], strlen(argv[1])+1);
		printf("Successfully sent %ld bytes\n", strlen(argv[1]));
	}
	else
		printf("FIFO not opened\n");

	close(fd);	
	return 0;
}

