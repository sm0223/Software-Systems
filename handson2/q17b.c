#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>
void main()
{

	int fd[2];
	pipe(fd);
	
	if (!fork()) {
		close(fd[0]);
		dup2(fd[1], 1); // making 1 as fd[1]
		execl("/bin/ls", "ls", "-l", NULL);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		execl("/bin/wc", "wc", (char *)0);
	}
	wait(0);
}
