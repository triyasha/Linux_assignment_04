#include<stdio.h>
#include<string.h>
#include<pthread.h>

pthread_once_t my_code = PTHREAD_ONCE_INIT;

void my_once()
{
	printf("Initialization code\n");
}

void *thread(void *args)
{
	printf("In thread %d\n",(int *)args);
	pthread_once(&my_code , (void *)my_once);

	printf("Exiting thread %d\n", (int *)args);

	return NULL;
}

int main()
{
	pthread_t thd1, thd2, thd3;
	
	pthread_create(&thd1, NULL, thread, (void *)1);
	pthread_create(&thd2, NULL, thread, (void *)2);
	pthread_create(&thd3, NULL, thread, (void *)3);

	pthread_join(thd1, NULL);
	pthread_join(thd2, NULL);
	pthread_join(thd3, NULL);

	return 0;
}
