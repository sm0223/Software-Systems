#include<stdio.h>
#include<unistd.h>
#include<sys/select.h>

void main()
{
	int pipefds1[2];
	int pipefds2[2];
	pid_t cpid;
	char buf;

	pipe(pipefds1);
	perror("\nchild to parent pipe creation status : ");
	pipe(pipefds2);
	perror("\nparent to child pipe creation status: ");

	cpid = fork();
	char message[30];
	char *childsays = "Child Says Hello \n";
	char *parentsays = "Parent Says Hello \n";
	if (cpid != 0) { // Parent process 
		close(pipefds1[0]); 
      		close(pipefds2[1]); // Close WRITE END
      		write(pipefds1[1], parentsays, sizeof(parentsays));
      		read(pipefds2[0], message, sizeof(childsays));
     	 	printf("From Parent :  %s\n", message);
    	}
    	else { //child process
      		close(pipefds1[1]); // Close the unwanted pipe1 write side
      		close(pipefds2[0]); // Close the unwanted pipe2 read side
      		read(pipefds1[0], message, sizeof(parentsays));
      		printf("From child %s\n", message);
      		write(pipefds2[1], childsays, sizeof(childsays));
   	}
}
