
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
	char buf[100];

	address.sin_family = AF_INET; 
	address.sin_addr.s_addr = INADDR_ANY; //binding to localhost 
	address.sin_port = htons(20000); 



	serverfd = socket(AF_INET, SOCK_STREAM, 0); //create socket
	perror("Server Socket Creation status :"); 

	retval = bind(serverfd, (struct sockaddr *) &address, addresslen); //bind
	perror("Server Bind status :");
	
	retval = listen(serverfd, 2); //listen - max 2 in queue
	perror("Server listen status :");


	while(1) {
		clientfd = accept(serverfd, (struct sockaddr *) &address, (socklen_t*) &addresslen); //accept
		
		if(!fork()){        //let child handle the request
            close(serverfd);        //close socket descriptor of parent because it is not required in serving the request by child.
            read(clientfd, buf, sizeof(buf));
            write(1,buf, sizeof(buf));
            close(clientfd);
            return 0;        
        }
        else{ // Parent ready to accept
            close(clientfd);   //Close client Socket fd 
        }	
	}	
	close(serverfd);
	return 0;
}
