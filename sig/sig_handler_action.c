#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <errno.h>

void sig_handler(int);

int main(void)
{
	struct sigaction action;
	char buf[20];

	action.sa_handler = sig_handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = SA_RESTART;

	sigaction(SIGINT, &action, NULL);

	while(1)
	{
		printf("Enter string\n");
		int ret = read(0, buf, 20);//scanf("%s",buf);
		printf("scanf retured %d with error code %d and str: %s\n", ret, errno,buf);
	}
	return 0;
}

void sig_handler(int signum)
{
	printf("Signal %d handled\n",signum);
}
