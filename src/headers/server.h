#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include "error.h"

void dump(const unsigned char*, const unsigned int);

#ifndef SERVER
#define SERVER
void server(const char* ip, short port){
	//Needed variables
	int sockfd = -1, clientfd = -1;
	struct sockaddr_in sockaddr, clientaddr;
	struct in_addr inaddr;
	unsigned short network_port;
	unsigned long network_IP;
	int reuse_yes = 1, sin_size = sizeof(sockaddr), recv_length = -1;
	char buffer[1024];

	//Setup any variables
	network_port = htons(port);
	memset(buffer, '\0', 0);

	//Set sockaddr_in
        if((inet_aton(ip, &inaddr) == 0))
		fatal("The given IP address in dot notation is not valid", -1);
	sockaddr.sin_family = AF_INET;
	sockaddr.sin_port = network_port;
	sockaddr.sin_addr = inaddr;
	memset(sockaddr.sin_zero, '\0', 8);

	//Open socket
	if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
		fatal("Failure in opening the socket", -1);

	//Set the reusability option for the socket
	if(setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &reuse_yes, sizeof(int)) == -1)
		fatal("Failure setting the reusability option for the socket", -1);

	if(bind(sockfd, ((struct sockaddr*)&sockaddr), sizeof(sockaddr)) == -1)
		fatal("Failure on binding to socket", -1);

	if(listen(sockfd, 256) == -1)
		fatal("Unable to listen on the specific address and port", -1);

	while(1){
		sin_size = sizeof(struct sockaddr_in);
                if((clientfd = accept(sockfd, (struct sockaddr*)&clientaddr, &sin_size)) == -1)
                        fatal("Could not accept a connection with a client", -1);
                printf("Got a connection with %s @ %d", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));
                send(clientfd, "Hi!", 4, 0);
                //Recieve data
                recv_length = recv(clientfd, &buffer, strlen(buffer), 0);
                while(recv_length > 0)
                {
                        printf("Recieved %s\n\n", buffer);
                        dump(buffer, recv_length);
                        recv_length = recv(clientfd, &buffer, strlen(buffer), 0);
                        send(clientfd, "RECVD", 6, 0);
                }
                close(clientfd);
        }
        close(sockfd);
        return;
}
#endif

void dump(const unsigned char* data_buffer, const unsigned int length)
{
        unsigned char byte;
        for(unsigned int i = 0; i < length; i++)
        {
                byte = data_buffer[i];
                printf("%02x", data_buffer[i]);
                if(((i%16) == 15 || (i==length-1)))
                {
                        for(unsigned int j = 0; j < (15-(i%16)); j++)
                        {
                                printf("        ");
                        }
                        printf("| ");
                        for(unsigned int j=(i-(i%16)); j <= i; j++)
                        {
                                byte = data_buffer[j];
                                if(byte > 31 && byte < 127)
                                {
                                        printf("%c", byte);
                                }
                                else
                                        printf("?");
                        }
                        printf("\n");
                }
        }
}

