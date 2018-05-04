#include<stdio.h>
#include<dirent.h>
void main()
{
	DIR *dp;
	struct dirent *dptr;
	//int m=mkdir("/home/siddhant/Desktop/OS/dir1",0777);
	//printf("%d",m);
	dp=opendir("/home/siddhant/Desktop/OS/dir/dir1");


	while(NULL!=(dptr=readdir(dp)))
	{
		printf("%s\n",dptr->d_name);
		printf("%u\n",dptr->d_type);
	}
}
