#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>
#include<fcntl.h>
void main()
{

	int fd[2];
	pipe(fd);
	
	if (!fork()) {
		close(1);
		fcntl(fd[1], F_DUPFD, 0);
		close(fd[0]);
		execl("/bin/ls", "ls", "-l", NULL);
	}
	else
	{
		close(0);
		fcntl(fd[0], F_DUPFD, 0);
		close(fd[1]);	
		execl("/bin/wc", "wc", NULL);
	}
}
