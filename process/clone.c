#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sched.h>

int myfn();

#define STACK_SIZE (1024)
int main()
{
	int *st,k=9;
	st = (int *)malloc(STACK_SIZE);
	st = st+STACK_SIZE; //Pointing to the top of the stack considering stacks growns down
	pid_t p1;
	p1 = clone(myfn,st,SIGCHLD,NULL);
	printf("Stack address: local = %p heap = %p\n", &st, st);	
	if(p1<0)
			perror("error in fork:");
	printf("before child.....................\n");
	if(p1==0)
			printf("i am in child...............");
	else
			printf("i am from parent.......................\n");
}
int myfn()
{
	int x = 10;
	static int y =20;
	printf("i am from child fun %p  &x=%p\n",__func__, &x);
	printf("main =%p  &y = %p....\n",main,&y);


}
