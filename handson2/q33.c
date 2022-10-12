
// Server

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
int main(int argc, char const* argv[])
{
	int server_fd, sockfd, retval;
	struct sockaddr_in address;

	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	perror("Server Socket Creation status :")
	address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; //binding to localhost
    address.sin_port = htons(PORT);

	retval = bind(sockfd, address, sizeof(address))
	perror("Server Bind status :")
	
	retval = listen(sockfd, 2);
	perror("Server listen status :")

	int new_socket = accept(sockfd, address, sizeof(address))
	
	char buf[100];
	read(new_socket, buf, sizeof(buf);
	write(1, buf, sizeof(buf));
	
	return 0;
}
