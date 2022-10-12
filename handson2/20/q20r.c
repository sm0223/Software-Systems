#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include<fcntl.h>	
void main()
{
	int fd;
	fd = open("pipe1", O_RDONLY);
	char buf[10];
	read(fd, buf , 10);
	write(1,buf,10);
	close(fd);
}
