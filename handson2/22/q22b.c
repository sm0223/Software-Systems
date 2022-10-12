#include<unistd.h>
#include<fcntl.h>
#include<string.h>
#include<sys/select.h>
#include<stdio.h>
#include<sys/types.h>
#include <stdlib.h>
void main()
{
	int fd;
	fd = open("pipe1", O_RDONLY);
	char rbuf[20];

	fd_set rfds;
	struct timeval tv;
	int retval;

	/* Watch stdin (fd) to see when it has input. */

	FD_ZERO(&rfds);
	FD_SET(fd, &rfds);

	/* Wait up to 5 seconds. */

	tv.tv_sec = 5;
	tv.tv_usec = 0;

	retval = select(fd+1, &rfds, NULL, NULL, &tv);

	if (retval == -1){
		perror("select() error: ");
	}
	else if (retval) {
		read(fd, rbuf, sizeof(rbuf));
		write(1, rbuf, sizeof(rbuf));
	}
	else{
		printf("No data within five seconds.\n");
	}
}
