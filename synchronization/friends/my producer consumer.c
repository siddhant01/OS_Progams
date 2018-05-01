//without signal variables, note here i am using spinlock semaphore so problems are there
#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#define size 4

int buff[size];
sem_t empty;
sem_t full;
sem_t mutex;

int f=0;
void *producer()
{	
	sem_wait(&empty);
	sem_wait(&mutex);

	//critical section
	printf("This is producer\n");
	printf("Enter an item\n");
	//scanf("%d",&buff[f]);
	buff[f]=f;
	f=f+1;
	
	sem_post(&mutex);
	sem_post(&full);

}

void *consumer()
{
	do
	{
		sleep(1);
		sem_wait(&full);
		sem_wait(&mutex);
	
		//critical section
		printf("This is consumer \n");
		printf("item consumed is %d \n",buff[f-1]);
		f=f-1;
		
		sem_post(&mutex);
		sem_post(&empty);
	}
	while(1);
}
int main()
{
	int p;
	printf("Enter no. of producer");
	scanf("%d",&p);
	pthread_t pro[p];
	pthread_t con;

	sem_init(&mutex,0,1);
	sem_init(&empty,0,size);
	sem_init(&full,0,0);
	
	pthread_create(&con,NULL,consumer,NULL);	
	
	for(int i=0;i<p;i++)
		pthread_create(&pro[i],NULL,producer,NULL);
	for(int i=0;i<p;i++)
		pthread_join(pro[i],NULL);

	pthread_join(con,NULL);
}


