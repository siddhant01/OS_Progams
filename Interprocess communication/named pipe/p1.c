#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
int main()
{
	printf("p1");
	int res;
        res = mkfifo("fifo1",0777); //creates a named pipe with the name fifo1 in the root dir
        printf("named pipe created\n");
}
