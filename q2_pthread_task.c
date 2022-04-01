#include<stdio.h>
#include<string.h>
#include<pthread.h>

struct my_data
{
	int roll;
	char name[50];
	int marks;
};

void *function(void *args)
{
	printf("In function\n");

	struct my_data *s = (struct my_data *)args;

	printf("Roll no. : %d\t Name : %s\t Marks: %d\n",s->roll, s->name, s->marks);

	return NULL;
}

int main()
{
	struct my_data t;

	pthread_t tid;

	t.roll = 95;
	strcpy(t.name, "Triyasha Sen");
	t.marks = 99;

	pthread_create(&tid, NULL, function, &t);
	pthread_join(tid, NULL);

	pthread_exit(NULL);

	return 0;
}
