#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>
void main()
{
	int fd[2];
	pipe(fd);
	if (!fork()) {
		close(1); // close stdout  now "1" is free
		dup(fd[1]);  // now 1 is fd[1]
		close(fd[0]);
		// printf
		execl("/bin/ls", "ls", NULL);
	}
	else
	{
		// wait(0);
		close(0); //closing stdin now "0" is free
		dup(fd[0]); // 0 is fd[0]

		close(fd[1]); //fd[1] is closed now 1 is again stdout
		execl("/bin/wc", "wc", NULL); // now execl will give output to 1(STDOUT)
	}
}
