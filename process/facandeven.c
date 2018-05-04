#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int n;
	printf("Enter a no. for which the operation is to be carried: ");
	scanf("%d",&n);	
	int pid = fork();
	switch(pid)
	{
		case -1:
			printf("fork failed");
			exit(1);
		case 0:
			printf("This is the child\n");
			if(n%2==0)
				printf("the no. is even\n");
			else
				printf("the no. is odd\n");
			break;
		default:
			printf("This is the parent\n");
			wait();
			int f=1;
			for(int i=1;i<=n;i++)
				f=f*i;
			printf("The the factorial of %d is %d\n",n,f);
	}
}
