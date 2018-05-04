#include<stdio.h>
#include<pthread.h>

void *fun()
{
	printf("thread cread");
	pthread_exit(NULL);
}

int main()
{
	pthread_t *thread;
	int a=pthread_create(&thread,NULL,fun,NULL);
	pthread_join(thread,NULL);
	printf("thread joining");
	printf("parent thread");
}

