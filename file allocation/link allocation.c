#include<stdio.h>
#include<stdlib.h>

struct node{
int *info;
struct node *link;
};
struct node *start=NULL;


void insert(int no,int s)
{
	struct node *n=(struct node *)calloc(sizeof(struct node),1);
	if(n==NULL)
	{
		printf("Memmory full\n");
		exit(0);
	}

	n->info=(int *)calloc(sizeof(int),no+1);
	if(n->info==NULL)
	{
		printf("Memmory full\n");
		exit(0);
	}
	int i=0;
	for(i=0;i<s;i++)
		n->info[i]=1;
	n->info[i]=2;
	struct node *ptr=start;
	int p=0;
	while(ptr->link!=NULL)
	{
			if(p+1==no)
				break;
			p++;
			ptr=ptr->link;
	}
	n->link=ptr->link;
	ptr->link=n;
}

void insert_last(int no)
{
	struct node *n=(struct node *)calloc(sizeof(struct node),1);
	if(n==NULL)
	{
		printf("Memmory full\n");
		exit(0);
	}
	n->link=NULL;
	n->info=(int *)calloc(sizeof(int),no+1);
	if(n->info==NULL)
	{
		printf("Memmory full\n");
		exit(0);
	}
	int i=0;
	for(i=0;i<no;i++)
		n->info[i]=1;
	n->info[no]=2;
	if(start==NULL)
		start=n;
	else
	{
		struct node *ptr=start;
		while(ptr->link!=NULL)
			ptr=ptr->link;
		ptr->link=n;
	}
}

void triverse()
{
	struct node *ptr=start;
	int n=0;
	int i;
	while(ptr!=NULL)
	{
		printf("file %d  \n",n+1);
		i=0;
		while(ptr->info[i]!=2)
		{
			printf("%d    ",ptr->info[i]);
			i++;
		}
		printf("\n");
		n++;
		ptr=ptr->link;
	}
}


int main()
{
	int s,f=0;
	while(1)
	{
		printf("Enter the file size : ");
		scanf("%d",&s);

		insert_last(s);
		
		printf("Press 1 for entering more files : ");
		scanf("%d",&f);
		if(f!=1)
			break;
	}
	printf("giving the structure of the file\n");
	triverse();
	
	int n;
	while(1)
	{
		printf("Enter the position where you want to insert the file (should be less than what was the total) along with size : ");
		scanf("%d %d",&n,&s);
		
		insert(n,s);
		
		printf("Press 1 for entering more files : ");
		scanf("%d",&f);
		if(f!=1)
			break;
	}
	printf("giving the structure of the file\n");
	triverse();
}


























