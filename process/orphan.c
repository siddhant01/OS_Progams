#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	printf("forking starting\n");
	int pid = fork();
	switch(pid)
	{
		case -1:
			printf("fork failed");
			exit(1);
		case 0:
			printf("This is the child\n");
			for(int i=0;i<200;i++)
			{
				if(i==99)
					system("ps -l");
			}
			printf("orphan child id= %d and orphan's parent id= %d\n",getpid(),getppid());
			//exit(1);
			break;
		default:
			printf("This is the parent\n");
			printf("program process id= %d and program's parent id= %d\n",getpid(),getppid());
			printf("now parent process exits\n");
			//exit(1);
	}
}
