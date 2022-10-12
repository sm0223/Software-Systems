
// Client

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
	long addresslen = sizeof(address);
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	perror("Client Socket Creation status :");
	address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;//inet_addr("127.0.0.1");
    address.sin_port = htons(20000);

	// retval = bind(sockfd, (struct sockaddr *)&address, sizeof(address));
	// perror("Client Bind status :");
	
	if ((connect(sockfd, (struct sockaddr *)&address, addresslen))<0) 
    { 				
        perror("connect status: "); 
        exit(EXIT_FAILURE); 
    } 	
	char buf[20] = "This is Client";
	write(sockfd, &buf, sizeof(buf));	
	close(sockfd);
	return 0;
}
