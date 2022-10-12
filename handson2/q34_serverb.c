
// Server

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>


void *connectionHandler(void *sd){
    int clientfd = *(int*)sd;
    char buf[100];

    read(clientfd, buf, sizeof(buf));
	write(1, buf, sizeof(buf));
    return 0;
}

int main()
{
	int clientfd, serverfd, retval, new_socket; 
	struct sockaddr_in address; 
	long addresslen = sizeof(address); 
	char buf[100];

	pthread_t pthreads;

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
		
		if(pthread_create(&pthreads, NULL, connectionHandler, (void *) &clientfd) < 0){
            perror("Not able to create the thread");
            return -1;
        }
        else{ // Parent ready to accept
            close(clientfd);   //Close client Socket fd 
        }	
	}	
	close(serverfd);
	return 0;
}
