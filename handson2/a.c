#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>	
void main()
{

	int fd;
	mkfifo("pipe1");
	fd = open("pipe1", O_WRONLY);
	write(fd, "Hello ", 6);
}
