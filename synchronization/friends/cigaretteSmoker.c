#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
int table_used=1,generated=0,item_gen[2]={0};
char item[3]={'t','p','m'};
sem_t t;
void *agent()
{
	int i=0,j=0,k=0;
	do
	{
		sem_wait(&t);
		if(table_used==1)
		{
			i=k;
			j=i+1;
			if(j==3)
				j=0;
			k=j;
			item_gen[0]=i;
			item_gen[1]=j;
			printf("agent produces %c and %c\n",item[i],item[j]);
			generated=1;
			table_used=0;
		}
		sem_post(&t);
	}
	while(1);

}

void *smoker(void *i)
{
	sem_wait(&t);
	int *val=(int *)i;
	if(table_used==0)
	{
		if(generated && item_gen[0]!=*val && item_gen[1]!=*val)
		{
			printf("Smoker %d has completed his smoking \n",*val);
			table_used=1;
			generated=0;
		}
	}
	sem_post(&t);
}

int main()
{
	pthread_t s1,s2,s0,agentpt;
	sem_init(&t,0,1);
	int m=0,j=1,k=2;
	printf("Smoker 0 has tobacco\n");
	printf("Smoker 1 has paper\n");
	printf("Smoker 2 has matches\n");
	pthread_create(&agentpt,NULL,agent,NULL);
	while(1)
	{
		pthread_create(&s0,NULL,smoker,(void*)&m);
		pthread_create(&s1,NULL,smoker,(void*)&j);
		pthread_create(&s2,NULL,smoker,(void*)&k);
	
		pthread_join(s0,NULL);
		pthread_join(s1,NULL);
		pthread_join(s2,NULL);
		sleep(1);
	}
	pthread_join(agentpt,NULL);
}
//note this program will not terminate. For eternity this process will go on.
