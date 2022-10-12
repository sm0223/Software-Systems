#include<stdio.h>
#include<unistd.h>
#include<sys/select.h>

void main()
{
	int pipefd[2];
	pid_t cpid;
	char buf;


	pipe(pipefd);
    perror("pipe creation status : ");

	cpid = fork();

	char str[10] = "abcdefghij";

	if (cpid == 0) {    
		// sleep(5);
		close(pipefd[1]);          
		while (read(pipefd[0], &buf, 1) > 0)
		   write(1, &buf, 1);
		
		close(pipefd[0]);

	} else {            
		close(pipefd[0]);          //closing read end
		write(pipefd[1], str, sizeof(str));
		close(pipefd[1]);          //closing writeend
	}
}
