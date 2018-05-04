#include<stdio.h>
#include<pthread.h>

void *fun1(char *a)
{
	printf("thread create\n");
	printf("%s\n",a);
	pthread_exit(NULL);
}

void *fun2(char *a)
{
	printf("thread create\n");
	printf("%s\n",a);
	pthread_exit(NULL);
}

int main()
{
	pthread_t *thread1;
	pthread_t *thread2;

	char *msg1="message1 from the parent";
	int a1=pthread_create(&thread1,NULL,fun1,(void *)msg1);

	char *msg2="message2 from the parent";
	int a2=pthread_create(&thread2,NULL,fun2,(void *)msg2);

	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);

	printf("thread joining\n");
	printf("parent thread\n");
}

