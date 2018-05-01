#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<string.h> 
int main() 
{
	char buffer[50];
	FILE *rd;
	rd=popen("ls","r");//note what have been listed by ls all has been written the file with rd file pointer
	fread(buffer, sizeof(char) , 50, rd); //reading 50 chars at a time from rd to buffer
	printf("%s\n", buffer);
	pclose(rd);
}

