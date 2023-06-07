#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int gData = 0;
pthread_mutex_t mutex;

void *inc(void *ignore)
{
	pthread_mutex_lock(&mutex);
	while(gData <=10)
	{
		printf("Before update gData: %d in %s\n",gData,__func__);
		sleep(1);
		gData++;
		printf("After  update gData: %d in %s\n",gData,__func__);
	}
	pthread_mutex_unlock(&mutex);
	pthread_exit(0);
}

void *dec(void *ignore)
{
	pthread_mutex_lock(&mutex);
	while(gData > 0)
	{
		printf("Before update gData: %d in %s\n",gData,__func__);
		sleep(1);
		gData--;
		printf("After  update gData: %d in %s\n",gData,__func__);
	}
	pthread_mutex_unlock(&mutex);
	pthread_exit(0);
}


int main(void)
{
	pthread_t t1, t2;
	pthread_mutex_init(&mutex, NULL);
	
	pthread_create(&t1, NULL, inc, NULL);
	pthread_create(&t2, NULL, dec, NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	
	printf("Fix by Mirafra: Shared data value is : %d\n", gData);
	return 0;
}

