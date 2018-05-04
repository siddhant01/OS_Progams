#include<stdio.h>
#include<pthread.h>

void *fun(char *a)
{
	printf("thread create\n");
	printf("%s\n",a);
	pthread_exit(NULL);
}

int main()
{
	pthread_t *thread;
	char *msg="message from the parent";
	int a=pthread_create(&thread,NULL,fun,(void *)msg);
	pthread_join(thread,NULL);
	printf("thread joining\n");
	printf("parent thread\n");
}

