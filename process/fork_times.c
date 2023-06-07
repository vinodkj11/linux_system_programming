#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
	fork();
	printf("1\n"); //2
	fork();
	printf("2\n"); //4
	fork();
	fork();
	printf("Hi\n");
	return 0;
}