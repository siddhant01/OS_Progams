//program to read from consol and writing in a file
#include<stdio.h>
#include<fcntl.h>   //for open()
#include<unistd.h>   //for read(),write(),close()
#include<string.h>

int main()
{
	int o=open("text.txt",O_WRONLY,700);  //always use 700 else error comes
	printf("%d\n",o);
	char buff[10];
	int r=read(0,buff,10);
	printf("%d\n",r);
	int w=write(o,buff,strlen(buff));
	printf("%d\n",w);
	close(o);
}
