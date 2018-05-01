#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
int main()
{
	printf("p2");
	int o,w;
	o=open("fifo1",O_WRONLY,0777);
	w=write(o,"written",7);
	printf("Process %d finished writing\n",getpid());
}
