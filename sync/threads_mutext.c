#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

int gData = 0;

void *inc(void *ignore)
{
	while(gData <=10)
	{
		gData++;
		printf("gData: %d in %s\n",gData,__func__);
		sleep(1);
	}
	pthread_exit(0);
}

void *dec(void *ignore)
{
	while(gData > 0)
	{
		gData--;
		printf("gData: %d in %s\n",gData,__func__);
		sleep(1);
	}
	pthread_exit(0);
}


int main(void)
{
	pthread_t t1, t2;

	pthread_create(&t1, NULL, inc, NULL);

	pthread_create(&t2, NULL, dec, NULL);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	printf("Shared data value is : %d\n", gData);
	return 0;
}

