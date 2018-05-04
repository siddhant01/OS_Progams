#include<unistd.h>
int main()
{
	if(write(99,"here is some data\n",18)!=18)
		write(2,"A write error has occurred on file descriptor 1\n",46);
}
