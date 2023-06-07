#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

int gData = 0;

sem_t sem;

void *inc(void *ignore)
{
	sem_wait(&sem);
	while(gData <=10)
	{
		printf("Before update gData: %d in %s\n",gData,__func__);
		sleep(1);
		gData++;
		printf("After  update gData: %d in %s\n",gData,__func__);
	}
	sem_post(&sem);
	pthread_exit(0);
}

void *dec(void *ignore)
{
	printf("--------------------Dec\n");
	sem_wait(&sem);
	while(gData > 0)
	{
		printf("Before update gData: %d in %s\n",gData,__func__);
		sleep(1);
		gData--;
		printf("After  update gData: %d in %s\n",gData,__func__);
	}
	sem_post(&sem);
	pthread_exit(0);
}


int main(void)
{
	pthread_t t1, t2;
	
	sem_init(&sem, 0, 1);

	pthread_create(&t1, NULL, inc, NULL);
	pthread_create(&t2, NULL, dec, NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	printf("Shared data value is : %d\n", gData);
	return 0;
}

