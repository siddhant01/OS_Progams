#include<stdlib.h>
#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
sem_t tp,pm,mt,smoke;
void *agent(){
sem_wait(&smoke);
int r=rand()%3;

switch(r){
	case 0:sem_post(&tp);
	       break;
	case 1:sem_post(&pm);
	       break;
	case 2:sem_post(&mt);
	       break;
}
pthread_exit(NULL);
}

void Smoker1(){
sem_wait(&tp);
printf("I have matches and got tobacco and paper\n ");
sem_post(&smoke);
pthread_exit(NULL);
}

void Smoker2(){
sem_wait(&pm);
printf("I have tobacco and got paper and matches\n");
sem_post(&smoke);
pthread_exit(NULL);
}
void Smoker3(){
sem_wait(&mt);
printf("I have paper and got matches and tobacco\n");
sem_post(&smoke);
pthread_exit(NULL);
}

int main(){
pthread_t ag,s1,s2,s3;
sem_init(&smoke,0,1);
sem_init(&tp,0,1);
sem_init(&pm,0,1);
sem_init(&mt,0,1);
sem_wait(&tp);
sem_wait(&pm);
sem_wait(&mt);
pthread_create(&ag,NULL,agent,NULL);
pthread_create(&s1,NULL,Smoker1,NULL);
pthread_create(&s2,NULL,Smoker2,NULL);
pthread_create(&s3,NULL,Smoker3,NULL);
pthread_join(ag,NULL);
pthread_join(s1,NULL);
pthread_join(s2,NULL);
pthread_join(s3,NULL);

}
