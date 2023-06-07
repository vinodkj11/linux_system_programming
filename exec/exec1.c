#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
	char *args[] = {NULL};
	printf("Calling... %d\n", getpid());
	execvp("./fork",args);
	printf("Done\n");
	return 0;
}
