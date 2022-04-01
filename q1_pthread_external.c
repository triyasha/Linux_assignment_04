#include<stdio.h>
#include<pthread.h>

void *thread_func(void *arg)
{
	printf("The thread function\n");

	for(int i=0; i<10; i++)
		printf("Value of i: %d\n",i);

	printf("Exiting thread\n");
}

int main()
{
	pthread_t tid;
	int r=0;

	pthread_create(&tid, NULL, thread_func, NULL);

	pthread_join(tid, NULL);

	pthread_exit(NULL);
	printf("Main thread terminated\n");

	return 0;
}
