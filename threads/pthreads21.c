#include<stdio.h>
#include<pthread.h>

struct st
{
	int n;
};
void *fun(struct st *o)
{
	printf("thread create\n");
	printf("%d\n",o->n);
	pthread_exit(NULL);
}
int main()
{
	pthread_t *thread;
	struct st o;
	(o).n=6;
	int a=pthread_create(&thread,NULL,fun,&o);
	pthread_join(thread,NULL);
	printf("thread joining\n");
	printf("parent thread\n");
}

