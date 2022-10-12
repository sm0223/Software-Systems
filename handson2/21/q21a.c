#include<unistd.h>
#include<fcntl.h>
#include<string.h>
void main()
{
	int fd, fd2;
	char wbuf[20] = "A Says Hello\n";
	char rbuf[20];
	fd = open("pipe1", O_WRONLY);
	fd2 = open("pipe2", O_RDONLY);
	write(fd, wbuf, sizeof(wbuf));
	read(fd2, rbuf, sizeof(rbuf));
	write(1, rbuf, sizeof(rbuf));
}
