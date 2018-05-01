//i used int i ans sleep() in order to show mingled result
#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
sem_t rw_mutex,rc_mutex;
    //wrt is common to reader n writer
	//rc to update readcount
int rcount=0;
    //count is to keep track of no of processes currently reading var
int var;

int i=0;
void *writer()
{
	sleep(i++);
	sem_wait(&rw_mutex);
	printf("write\n");
	scanf("%d",&var);
	printf("written value=%d\n",var);
	sem_post(&rw_mutex);
}

void *reader()
{
	sleep(i++);
	sem_wait(&rc_mutex);
	rcount++;
	if(rcount==1)
		sem_wait(&rw_mutex);
	sem_post(&rc_mutex);
	printf("read value=%d\n",var);
	sem_wait(&rc_mutex);
	rcount--;
	if(rcount==0)
		sem_post(&rw_mutex);
	sem_post(&rc_mutex);
}
int main()
{
	int rn,wn;
	printf("Enter no. of writers\n");
	scanf("%d",&wn);
	printf("Enter no. of readers\n");
	scanf("%d",&rn);

	pthread_t w[wn],r[rn];
	sem_init(&rw_mutex,0,1);
	sem_init(&rc_mutex,0,1);

	for(int i=0;i<wn;i++)
	pthread_create(&w[i],NULL,writer,NULL);

	for(int i=0;i<rn;i++)
	pthread_create(&r[i],NULL,reader,NULL);

	for(int i=0;i<wn;i++)
	pthread_join(w[i],NULL);
	for(int i=0;i<rn;i++)
	pthread_join(r[i],NULL);
}
