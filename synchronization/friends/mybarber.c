//for one barbar and many custormer
//it is very much like producer consumer problem
#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
sem_t barber,customer,waitingroom; //waiting room is mutex for updating the seats
int seats=4;  //no. of free seats in waiting room
void *barbercutting()
{
	do
	{
		sem_wait(&customer); //decrease customer
		sem_wait(&waitingroom); 
		
		seats+=1;	//increase the no. of seating in waiting room
		printf("barber is cutting hair\n");
		sleep(1);	//let barbar take 1 sec to cut hair
		
		sem_post(&waitingroom);	  
		sem_wait(&barber);  //after cutting hair barber sleeps
	}while(1);
}

void *customercoming()
{
	sem_wait(&waitingroom);
	if(seats>0)
	{
		seats=seats-1;
		sem_post(&customer);
		sem_post(&waitingroom);
		printf("customer in waiting room\n");
		sem_post(&barber);
	}
	else //for no seats available
	{
		sem_post(&waitingroom);
		printf("no free seat\n");
	}
}

int main()
{
	pthread_t bar,cus[100];	
	sem_init(&barber,0,1);
	sem_init(&waitingroom,0,1);
	sem_init(&customer,0,0);

	sem_wait(&barber);//to make sem 0, to make barber sleep initially
	
	pthread_create(&bar,NULL,barbercutting,NULL);
	for(int i=0;i<100;i++)
		pthread_create(&cus[i],NULL,customercoming,NULL);
//	sleep(1);
	
	
	for(int i=0;i<100;i++)
		pthread_join(cus[i],NULL);
	pthread_join(bar,NULL);
}
