#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include<fcntl.h>	
void main()
{
	int fd;
	fd = open("pipe1", O_RDONLY);

	fd_set set_of_fds;

	struct timeval tv;
	int retval;

	FD_ZERO(&set_of_fds); // Clears the set of fds
	FD_SET(fd, &set_of_fds); //Add pipe1 to the set

	tv.tv_sec = 10; // Wait 10s
	tv.tv_usec = 0;

	retval = select(1, &set_of_fds, NULL, NULL, &tv);
	if (retval == -1){
		    perror("select() error: ");
	}
	else if (retval){

		printf("Data is available now.\n");
		while (read(fd, &buf, 1) > 0)
		   write(1, &buf, 1);
	}
	else
	   printf("No data within five seconds.\n");
}
