#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
sem_t wrt,rc;
    //wrt is common to reader n writer
	//rc to update readcount
int count=0;
    //count is to keep track of no of processes currently reading var
int var;
void *writer()
{
	sem_wait(&wrt);
	printf("write\n");
	scanf("%d",&var);
	printf("written value=%d\n",var);
	sem_post(&wrt);
	pthread_exit(NULL);
}

void *reader()
{
	sem_wait(&rc);
	count++;
	if(count==1)
		sem_wait(&wrt);
	sem_post(&rc);
	printf("read value=%d",var);
	sem_wait(&rc);
	count--;
	if(count==0)
		sem_post(&wrt);
	sem_post(&rc);
	pthread_exit(NULL);
}
int main()
{
	pthread_t w,r;
	sem_init(&wrt,0,1);
	sem_init(&rc,0,1);
	pthread_create(&w,NULL,writer,NULL);
	pthread_create(&r,NULL,reader,NULL);
	pthread_join(w,NULL);
	pthread_join(r,NULL);
}
