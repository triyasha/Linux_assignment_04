#include<stdio.h>
#include<pthread.h>

int main()
{
	pthread_t tid;

	struct sched_param p;

	int policy;

	pthread_getschedparam(pthread_self(), &policy, &p);
	printf("Default: \t Policy: %d \t Priority: %d\n",policy, p.sched_priority);

	policy = SCHED_FIFO;
	p.sched_priority = 2;

	pthread_setschedparam(pthread_self(), policy, &p);

	pthread_getschedparam(pthread_self(), &policy, &p);
	printf("After SetSched: \t Policy: %d \t Priority: %d\n",policy, p.sched_priority);

	return 0;
}
