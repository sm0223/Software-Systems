#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
void main() {
	int pipefd[2];

	pipe(pipefd);
	perror("Status : ");
	char buf1[5], buf2[5];
	scanf("%s", buf1);
	write(pipefd[1], &buf1, sizeof(buf1)); //write to the write end of pipe
	read(pipefd[0], &buf2, sizeof(buf2)); //read from the read end
	printf("%s",buf2);

}