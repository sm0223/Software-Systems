#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>
void main()
{
	mkfifo("pipe1", 0777);
	perror("Status: ");
}