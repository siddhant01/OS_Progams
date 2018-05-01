#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
int main()
{
	printf("p3");
	int o,r;
	char buffer[100];
	o=open("fifo1",O_RDONLY,0777);
	r=read(o,buffer,100);
	printf("Total bytes read: %d\n",r);	
	printf("%s was passed to me \n",buffer);
	printf("Process %d finished\n",getpid());
}
