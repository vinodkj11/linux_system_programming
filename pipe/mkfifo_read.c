#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(void)
{
	int fd;

	fd = open("./fifo1", O_RDONLY);
	if(fd > 0)
	{
		char str[20];
		printf("Reading\n");
		read(fd, str, 20);
		printf("Successfully read %s string\n", str);
	}
	else
		printf("FIFO not opened\n");
        close(fd);	
	return 0;
}

