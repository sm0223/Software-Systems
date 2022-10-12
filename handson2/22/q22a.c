#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<stdio.h>
void main()
{
	int fd, fd2;
	char wbuf[20] = "A Says Hello\n";
	fd = open("pipe1", O_WRONLY);
	char ch = getchar(); 	//to stop the control 
	write(fd, wbuf, sizeof(wbuf));
}
