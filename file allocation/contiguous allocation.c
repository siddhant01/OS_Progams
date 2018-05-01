//for given input as file starting_index size

#include<stdio.h>
#include<stdlib.h>

int *a;
int n;
int file[10][2]={0};
int fn=0;

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

void allocation(int s,int e)
{
	if(s<0 && e>=n)						//
	{									//
		printf("wrong file size\n");	//  comment these in case of circular array
		return;							//
	}									//
	int f=0,i;
	for(i=s;i<=e;i++)
	{
		if(a[i]!=0)    //for circular array use a[i%n]!=0
		{
			f=1;
			break;
		}
	}
	if(f==1)
	{
		printf("space not free\n");
		return;
	}
	else
	{
		file[fn][0]=s;
		file[fn][1]=e;
		fn++;
		for(i=s;i<=e;i++)
			a[i]=1;                 //for circular array use a[i%n]=1;
		printf("written to drive\n");
	}
	print();
}

int main()
{
	printf("Enter the initial size of the array : ");
	scanf("%d",&n);
	a=(int *)calloc(sizeof(int),n);
	int s,e,f;
	while(1)
	{
		printf("Enter the file starting location and size : ");
		scanf("%d %d",&s,&e);

		allocation(s,e+s-1);
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
