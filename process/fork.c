#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int a = 5;

int main(void)
{
	int x = 100;
	int y = 123;
	pid_t pid = -1;

	pid = fork();

	if(pid == 0)
	{
		printf("Myself child process and my id : %d and my parent id : %d\n", getpid(), getppid());
		x = 200;
		a = 10;
		y = 345;
		sleep(2);
/*	printf("x= %d &x = %p\n",x, &x);
	printf("y= %d &y = %p\n",y, &y);
	printf("a= %d &a = %p\n",a, &a);
*/
	}
	else
	{
		printf("Myself parent process and my id : %d and my parent id : %d\n", getpid(), getppid());
		x = 300;
		a = 20;
		y = 789;
		sleep(2);
/*	printf("x= %d &x = %p\n",x, &x);
	printf("y= %d &y = %p\n",y, &y);
	printf("a= %d &a = %p\n",a, &a);
*/	}
	printf("x= %d &x = %p\n",x, &x);
	printf("y= %d &y = %p\n",y, &y);
	printf("a= %d &a = %p\n",a, &a); 
//	getchar();
//	while(1){}
	return 0;
}


