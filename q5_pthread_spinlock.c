#include<stdio.h>
#include<pthread.h>

static pthread_spinlock_t sp_lock;

void *thread1_func(void *args)
{
	int i;
	printf("In thread1 function\n");

	printf("Entering thread1 spin lock\n");
	pthread_spin_lock(&sp_lock);

	for(i=0; i<10; i++)
		printf("thread1: %d\n",i*2);

	pthread_spin_unlock(&sp_lock);
	printf("Exiting thread1 spinlock\n");

	printf("Exiting thread1\n");

	return NULL;
}

void *thread2_func(void *args)
{
	int i;
	printf("In thread2 function\n");

	printf("Entering thread2 spin lock\n");
	pthread_spin_lock(&sp_lock);

	for(i=0; i<10; i++)
		printf("thread2: %d\n",i*5);

	pthread_spin_unlock(&sp_lock);
	printf("Exiting thread2 spinlock\n");

	printf("Exiting thread2\n");

	return NULL;
}

int main()
{
	pthread_t tid1, tid2;

	printf("In Main thread: %ld\n",pthread_self());
	if(pthread_spin_init(&sp_lock, PTHREAD_PROCESS_PRIVATE) != 0)
		perror("spin init");

	pthread_create(&tid1, NULL, thread1_func, NULL);
	pthread_create(&tid2, NULL, thread2_func, NULL);

	pthread_join(tid1, NULL);
	pthread_join(tid2, NULL);

	printf("Exiting Main thread\n");

	return 0;
}
