//it is counting no. of words from the terminal (file)
#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h>
#include<string.h>
int main() 
{
	char buffer[50];
	sprintf(buffer,"name first");

	FILE *rd;
	rd=popen("wc -c","w");//here we are opening the terminal with wc -c now we write on the terminal 'name first' then we close crl+d then the result is no. of letters Eg >> wc -c  enter name first ctr+d, then you get 10


	fwrite(buffer,sizeof(char),strlen(buffer),rd);

	pclose(rd);
}

