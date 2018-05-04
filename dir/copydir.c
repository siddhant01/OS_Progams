#include<stdio.h>
#include<dirent.h>
#include<unistd.h>
#include<fcntl.h>
void main(int n, char *d[])
{
	
	printf("n value %d\n",n);
	printf("source directory %s\n",d[1]);
	printf("destination directory %s\n",d[2]);

	DIR *dpo;
	struct dirent *dpor;
	int m=mkdir(d[2],0777);
	printf("%d\n",m);
	dpo=opendir(d[1]);


	while(NULL!=(dpor=readdir(dpo)))
	{
		char *fn=dpor->d_name;
		//printf("%s\n",fn);
		int l;
		for(l=0;fn[l]!=NULL;l++);
		//printf("length %d\n",l);
		if(l>4 && fn[l-1]=='f' && fn[l-2]=='d' && fn[l-3]=='p' && fn[l-4]=='.')
		{
			printf("copying %s\n",fn);
			

			char sn[100];
			int sl;
			for(sl=0;d[1][sl]!=NULL;sl++)
				sn[sl]=d[1][sl];
			sn[sl++]='/';
			for(int i=0;i<=l;i++)
				sn[sl++]=fn[i];
			printf("path of source file %s\n",sn);


			char dn[100];
			int dl;
			for(dl=0;d[2][dl]!=NULL;dl++)
				dn[dl]=d[2][dl];
			dn[dl++]='/';
			for(int i=0;i<=l;i++)
				dn[dl++]=fn[i];
			printf("path of destination file %s\n",dn);

			int s_o=open(sn,O_RDONLY,0777);
			int d_o=open(dn,O_CREAT|O_WRONLY,0777);
	
			char b[1024];
			int r=0;
			int w=0;
			while((r=read(s_o,b,1024))>0)
			{
				if((w=write(d_o,b,r))==-1)
				{
					break;
				}
			}
			close(s_o);
			close(d_o);
		}
	}
	closedir(dpo);
}













