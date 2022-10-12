
#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>	
void main()
{

	int fd2[2];
	pipe(fd2);
	perror("pipe status :");
	if(!fork()){

		int fd[2];
		pipe(fd);
		if(!fork()) { // 2nd child
			dup2(fd[1], 1);
			execl("/bin/ls", "ls", "-l",NULL);
		}
		else{ //1st child

			wait(0);
			dup2(fd[0], 0);
			close(fd[1]); //closing fd[1] so that execl outputs to 1(fd2[1])
			dup2(fd2[1], 1); // making 1 to fd2[1]
			execl("/bin/grep", "grep", "^d", NULL);
		}
	}
	else
	{
		wait(0);
		dup2(fd2[0], 0); 
		close(fd2[1]); // closing fd2[1] so that execl writes to 1(stdout)
		execl("/bin/wc", "wc", NULL);	
	}
}
