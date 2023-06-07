#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <semaphore.h>

#define KB (1024)
#define SEM_SIZE 1024

int main(void)
{
	void *shm_addr = NULL;;
	char str[50];
	int shmid;

	sem_t *lock;
	int mutex_id;
	mutex_id = shmget((key_t)1111, SEM_SIZE, 0666|IPC_CREAT);
        lock = shmat(mutex_id, NULL,0);
	int ret = sem_init(lock,1,1);
	printf("Ret : %d\n",ret);

	printf("Entering Semaphore and count : %d\n", *((char*)lock));
	sem_wait(lock);
	printf("Entered Semaphore\n");
	shmid = shmget((key_t)1234, KB, 0666|IPC_CREAT);
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
	printf("Enter the string to send\n");
	read(0, str, 50);
	strncpy((char*)shm_addr, str, 40);
	printf("Written string into the shamred memory is %s\n",(char*)shm_addr);
	shmdt(shm_addr);
	sem_post(lock);
	shmdt(lock);

	return 0;
}

