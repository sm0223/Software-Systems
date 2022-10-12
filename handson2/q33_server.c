
// Server

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
int main()
{
	int clientfd, serverfd, retval, new_socket;
	struct sockaddr_in address;
	long addresslen = sizeof(address);

	address.sin_family = AF_INET;
	address.sin_addr.s_addr = INADDR_ANY; //binding to localhost
	address.sin_port = htons(20000);



	serverfd = socket(AF_INET, SOCK_STREAM, 0); //SOCK_DGRAM for UDP
	perror("Server Socket Creation status :");

	retval = bind(serverfd, (struct sockaddr *)&address, addresslen); 
	perror("Server Bind status :");
	
	retval = listen(serverfd, 2); //max two in queue
	perror("Server listen status :");


	
	clientfd = accept(serverfd, (struct sockaddr *)&address, (socklen_t*) &addresslen);
     	
	char buf[20];
	read(new_socket, buf, sizeof(buf));
	write(1, buf, sizeof(buf));
	


	close(new_socket);
	return 0;
}
