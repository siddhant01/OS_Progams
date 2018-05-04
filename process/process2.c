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
	pid=fork();       //for child pid will be 0 and for parent it will be smth else
	printf("%d\n",pid);  //it will give 0 as just after forking child is 0
			     //if parent will wait then it will print something other
/*
	printf("%d\n",getpid());
*/	
	wait();
	printf("%d    %d\n",getpid(),getppid());

	//check ps, wait, getpid(), getpid(), exec(), exit();
	//note the pid of the child gets different eventually because it runs exec() method for creating its process id.(wrong)
	

}
