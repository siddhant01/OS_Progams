//program to read from consol and then seek and write in a file.
#include<stdio.h>
#include<fcntl.h>   //for open()
#include<unistd.h>   //for read(),write(),close()
#include<string.h>

int main()
{
	int o=open("text.txt",O_RDWR,700);
	printf("%d\n",o);
	char buff[10];
	printf("writing at the end\n");
	int r=read(0,buff,10);
	printf("%d\n",r);
	int l=lseek(o,-1,SEEK_END);
	printf("%d\n",l);
	int w=write(o,buff,strlen(buff)-1);
	printf("%d\n",w);
}
