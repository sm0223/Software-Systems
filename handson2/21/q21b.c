#include<unistd.h>
#include<fcntl.h>
#include<string.h>
void main()
{
	int fd, fd2;
	char wbuf[20] = "B Says Hello\n";
	char rbuf[20];
	fd = open("pipe1", O_RDONLY);
	fd2 = open("pipe2", O_WRONLY);
	write(fd2, wbuf, sizeof(wbuf));
	read(fd, rbuf, sizeof(rbuf));
	write(1, rbuf, sizeof(rbuf));


}
