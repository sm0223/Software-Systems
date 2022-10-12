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

	char str[10];	

	if (cpid == 0)   //Child Process
	{
		close(pipefd[1]);          
		while (read(pipefd[0], &buf, 1) > 0)
		   write(1, &buf, 1);
		close(pipefd[0]);
	} 
	else //Parent 
	{              
		close(pipefd[0]);          //closing read end
		printf("ENTER STR\n");
		scanf("%s",&str);
		write(pipefd[1], str, sizeof(str));
		close(pipefd[1]);          //closing writeend
	}
}
