#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>


int main(void)
{
	int ret = mkfifo("fifo1", 0777);

	if(ret == 0)
		printf("FIFO created successfully\n");
	else
		printf("Failed to create FIFO\n");

	return 0;
}

