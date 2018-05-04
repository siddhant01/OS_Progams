//not complete
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<math.h>
#include<fcntl.h>

int main()
{
	int opid=getpid();
	int *count=(int *)malloc(sizeof(int));
	int n;
	printf("Enter a no. of forks to be done to show cascading termination: ");
	scanf("%d",&n);	
	for(int i=0;i<n;i++)
	{
		sleep((float)i/10);
		fork();
	}
	
	if(getpid()!=opid)
	{
		*count+=1;
	}
	for(int i=0;i<n;i++)
		wait();
	if(getpid()==opid)
	{
		printf("total no. of child process %d",*count);
	}
}
