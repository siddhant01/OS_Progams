#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n;
	printf("Enter no of files to be indexed");
	scanf("%d",&n);
	int **a=(int **)calloc(sizeof(int),n); // note it is array of pointer not pointer to pointer
	
	int file[10]={0};
	int fn;
	int s;
	int i,f=0,j;
	while(1)
	{
		printf("Enter file size");
		scanf("%d",&s);
		a[fn]=(int *)calloc(sizeof(int),s);
		for(i=0;i<s;i++)
			a[fn][i]=1;
		file[fn]=s;
		fn++;
		
		printf("Press 1 for entering more files : ");
		scanf("%d",&f);
		if(f!=1)
			break;
	}
	
	printf("printing the structure of the disk\n");
	for(i=0;i<fn;i++)
	{
		printf("file %d \n",i+1);
		for(j=0;j<file[i];j++)
			printf("%d  ",a[i][j]);
		free(a[i]);
		printf("\n");
	}
	free(a);
}
