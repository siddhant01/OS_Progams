#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>

sem_t emp,full,m;
int que[5];
int total=4,count=0,nextp,nextc;

void *producer()
{
	printf("this is producer\n");
	printf("produce item\n");
	scanf("%d",&nextp);
	sem_wait(&emp);
        sem_wait(&m);
        count+=1;
	if(count<5)
	{
		que[count]=nextp;
		printf("item produced = %d at location= %d\n",que[count],count);
	}
	else
	{
		printf("space not available\n");
	}
	sem_post(&m);
	sem_post(&full);
	pthread_exit(NULL);
}

void *consumer()
{
	printf("this is consumer\n");
    sem_wait(&full);
	sem_wait(&m);
	nextc=que[count];
	count-=1;
	sem_post(&m);
	sem_post(&emp);
	if(count>=0)
	{
		printf("Consumed item is %d\n",nextc);
	}
	else
	{
		printf("nothing to consume\n");
	}
}
int main()
{
	int pr,cn;
	pthread_t p[4],c[4];
	printf("Enter the num of producer and consumer\n");
	scanf("%d",&pr);
	scanf("%d",&cn);
	sem_init(&emp,0,4);
	sem_init(&full,0,4);
	sem_init(&m,0,1);
	for(int i=0;i<4;i++)
	{
		sem_wait(&full);
	}
	for(int m=0;m<pr;m++)
	{
		pthread_create(&p[m],NULL,producer,NULL);
	}
	for(int k=0;k<pr;k++)
	{
		pthread_join(p[k],NULL);
	}
	for(int n=0;n<cn;n++)
	{
		pthread_create(&c[n],NULL,consumer,NULL);
	}
	for(int n=0;n<cn;n++)
	{
		pthread_join(c[n],NULL);
	}
}
