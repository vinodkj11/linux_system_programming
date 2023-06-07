#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define KB 1024

int main(void)
{
	void *shm_addr = NULL;;
	char str[20];
	int shmid;

	shmid = shmget((key_t)1234, KB, 0666);
	if(shmid >= 0)
		printf("Shared memory created with shmid : %d\n", shmid);
	else
	{
		printf("Failed to create shared memory\n");
		exit(0);
	}
	shm_addr = shmat(shmid,NULL,0);

	if(shm_addr !=NULL)
		printf("Process attached at addr: %p\n", shm_addr);
	else
	{
		printf("Failed to attach the shared memory\n");
		exit(0);
	}
	printf("String read from shared memory is %s\n",(char*)shm_addr);

	shmdt(shm_addr);

	return 0;
}

