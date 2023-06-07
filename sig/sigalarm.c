#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

void sigalrm_handler(int signum)
{
	printf("You Are Lazy \n");
	exit(0);
}

int main()
{
	char nam[30];
	signal(SIGALRM,sigalrm_handler);
	printf("Enter Your Name \n");
	alarm(5);
	scanf("%s",nam);
	printf("%s : Your Name is So Sweet \n",nam);
	return 0;
}
