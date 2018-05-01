//for given input as file size

#include<stdio.h>
#include<stdlib.h>

int *a;
int n;
int file[10][2]={0};
int fn=0;

int start=0;

void print()
{
	int i=0;
	for(i=0;i<n;i++)
		printf("%d    ",a[i]);
	printf("\n");
}

void printfiles()
{
	int i;
	for(i=0;i<fn;i++)
	{
		printf("file %d start=%d ending=%d \n",i,file[i][0],file[i][1]);
	}
}

void allocation(int s)
{
	if(s>=n)						    
	{									
		printf("wrong file size\n");	
		return;							
	}									
	if(start+s-1>=n)
	{
		printf("file to big to be stored\n");
		return;
	}
	int i;
	file[fn][0]=start;
	file[fn][1]=start+s-1;
	fn++;
	for(i=start;i<=start+s-1;i++)
		a[i]=1;               
	printf("written to drive\n");
	start=start+s;
	print();
}

int main()
{
	printf("Enter the initial size of the array : ");
	scanf("%d",&n);
	a=(int *)calloc(sizeof(int),n);
	int s,f;
	while(1)
	{
		printf("Enter the file size : ");
		scanf("%d",&s);

		allocation(s);
		printf("Press 1 for entering more files : ");
		scanf("%d",&f);
		if(f!=1)
			break;
		
	}
	printf("giving the structure of the file\n");
	print();
	printf("files are\n");
	printfiles();
	free(a);
}
