#include<stdio.h>
#include<pthread.h>

struct st
{
	int n;
};
int *fun(struct st *o)
{
	printf("thread create\n");
	printf("%d\n",o->n);
	return o->n*5;
	pthread_exit(NULL);
}
int main()
{
	pthread_t *thread;
	struct st o;
	(o).n=6;
	int a=pthread_create(&thread,NULL,fun,&o);

	int *r;
	pthread_join(thread,r);
	printf("thread joining\n");
	printf("parent thread\n");
	printf("%d\n",*r);
}
