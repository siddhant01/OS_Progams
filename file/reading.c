//program to read from file and writing to console
#include<stdio.h>
#include<fcntl.h>   //for open()
#include<unistd.h>   //for read(),write(),close()
#include<string.h>

int main()
{
	int o=open("text.txt",O_RDONLY,777);
	printf("%d\n",o);
	char buff[10];
	int r=read(o,buff,10);
	printf("%d\n",r);
	printf("len of read is %d \n",strlen(buff));
	int w=write(1,buff,strlen(buff));
	printf("%d\n",w);
	close(o);
}
