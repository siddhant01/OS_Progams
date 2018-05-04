#include<stdio.h>
#include<unistd.h>
void main()
{
	int pid;
	printf("parent %d and parent's parent %d \n",getpid(),getppid());

	/*
	if we do just
	fork(); // then there will be something else
	*/
	printf("after fork\n");
	pid=fork();
	//printf("%d\n",pid);  //it will give 0 as just after forking child is 0
			     //if parent will wait then it will print something other
/*
	printf("%d\n",getpid());
*/	
	wait();
	printf("%d    %d\n",getpid(),getppid());
	

}
