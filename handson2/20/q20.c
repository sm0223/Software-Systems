#include<unistd.h>
#include<fcntl.h>
#include<string.h>
void main()
{
	int fd;
	char buf[10] = "abcde\n";
	fd = open("pipe1", O_WRONLY);
	write(fd, buf, 10);
}
