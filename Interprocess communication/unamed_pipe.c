#include<stdio.h>
#include<unistd.h>
int main()
{
	int fd[2];
	char buff[10];
	pipe(fd);
	int p=fork();
	if(p==0)   //child writing
	{
		close(fd[0]);
		int a=write(fd[1],"hello",6);
	}
	else
	{
		wait(); //for making the parent wait until child has written
		close(fd[1]);
		int a=read(fd[0],buff,10);
		printf("%s",buff);
	}
}
