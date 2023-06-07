#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>

int n =0;
void sig_handler(int);

int main(void)
{
	signal(SIGHUP, sig_handler);
	printf("Just started....\n");
	sleep(2);
	raise(SIGHUP);

	while(1)
	{
		sleep(1);
		printf("Counting... %d\n",n++);
	}
	return 0;
}

void sig_handler(int signum)
{
	printf("Signal %d handled\n",signum);
	//reset counter
	n = 0;
}
