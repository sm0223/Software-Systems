#include<stdio.h>
#include<unistd.h>
#include <sys/wait.h>	
#include<fcntl.h>
void main()
{

	int fd;
	char *str;
	fd = open("pipe1", O_WRONLY);
	
	printf("ENTER STR\n");
		scanf("%s",&str);
	write(fd, str, sizeof(str));
}
