#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int count=0;
pthread_mutex_t lock;
void *fun1()
{
	pthread_mutex_lock(&lock);
	for(int i=0;i<10;i++)
	{
		sleep(1);
		printf("value increamented\n");
		count++;
		printf("%d\n",count);
	}
	pthread_mutex_unlock(&lock);
	pthread_exit(NULL);
}
void *fun2()
{
	pthread_mutex_lock(&lock);
	for(int i=0;i<10;i++)
	{
		sleep(1);
		printf("value decreamented\n");
		count--;
		printf("%d\n",count);
	}
	pthread_mutex_unlock(&lock);
	pthread_exit(NULL);
}

int main()
{
	
	pthread_t *thread1,*thread2;
	int a=pthread_create(&thread1,NULL,fun1,NULL);
	int b=pthread_create(&thread2,NULL,fun2,NULL);
	pthread_join(thread1,NULL);
	pthread_join(thread2,NULL);
	printf("thread joining");
	printf("parent thread");
}

