//у илюши (не сдавал)
//ворнинги отрубаем 
//какая теория?

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFER_SIZE 256
#define CONNECTIONS_ALLOWED 2
#define APPROVE_MESSAGE "Server has received your message\n"
#define APPROVE_MESSAGE_SIZE sizeof(APPROVE_MESSAGE)

int findUnusedFd(int *fdIsUsed) {
	for (int i = 0; i < CONNECTIONS_ALLOWED; i++) {
		if ( !fdIsUsed[i] ) {
			return i;
		}
	}
}

int main ( int argc, char ** argv ) {
	//should enter listening port, SocketAddress(IP and PORT) to translate the connection.
	if ( argc < 4 ) {
		fprintf(stderr, "No port entered\n");
		return 1;
	}

	printf("Process is going to listen on local host on port : %s\n", argv[1]);
	printf("Translating all input to : %s:%s\n", argv[2], argv[3]);

	//file descriptors for client and server
	int server_fd = 0; 
	int transfer_fd[CONNECTIONS_ALLOWED] = {0};
	int client_fd[CONNECTIONS_ALLOWED] = {0};
	int fdIsUsed[CONNECTIONS_ALLOWED] = {0};
	
	int port_number = atoi(argv[1]);
	int transfer_port_number = atoi(argv[3]);
	int client_address_size = 0;

	//socket interfaces
	//declaration : 
	/*struct sockaddr_in {
  		short   sin_family; // must be AF_INET 
  		u_short sin_port;
  		struct  in_addr sin_addr;
  		char    sin_zero[8]; // Not used, must be zero 
	};*/

	//socket INTERNET TCP/IP address
	struct sockaddr_in server_address = {0};
	struct sockaddr_in client_address = {0};
	struct sockaddr_in transfer_to_address = {0};
	
	server_address.sin_family = AF_INET;
	transfer_to_address.sin_family = AF_INET;
	
	//in order to convert port number in correct byte order
	server_address.sin_port = htons(port_number);
	transfer_to_address.sin_port = htons(transfer_port_number);

	//the IP address of server is LOCAL HOST
	server_address.sin_addr.s_addr = INADDR_ANY;
	transfer_to_address.sin_addr.s_addr = inet_addr(argv[2]);
	
	char buffer[BUFFER_SIZE] = {0};

	//creating new listening TCP socket
	//0 -- protocol choosed automatically
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if ((-1 == server_fd)) {
		perror("Could not create socket\n");
		return 1;
	}

	//binding socket to an address (assigning address to it, file descriptor)
	//sockaddr used for different kind of addresses
	/*struct sockaddr {
  		unsigned short   sa_family;
   		char             sa_data[14];
	};*/

	printf("Binding socket ...\n");
	if (0 != bind( server_fd, 
				   (struct sockaddr *) &server_address, 
				   sizeof(server_address))
		) {
		perror("Could not bind socket to address\n");
		return 1;
	}

	// printf("Connecting to transfer socket...\n");


	if (0 != listen(server_fd, CONNECTIONS_ALLOWED)) {
		perror("Could not listen to interface\n");
		return 1;
	}

	client_address_size = sizeof(client_address);
	
	int bytes_read = 0;
	fd_set readSet;
	FD_ZERO(&readSet);
	
	int maxFd = server_fd + 1;
	int clients_count = 0;
	int bytesRead = 0;

	while (1) {
		FD_ZERO(&readSet);
		FD_SET(server_fd,&readSet);
		for (int i = 0; i < CONNECTIONS_ALLOWED; i++) {
			if (fdIsUsed[i]) {
				FD_SET(client_fd[i], &readSet);
				FD_SET(transfer_fd[i], &readSet);
			}
		}

		int ret_value = select(maxFd, &readSet, NULL, NULL, NULL);
		for (int i = 0; i < CONNECTIONS_ALLOWED; ++i) {
			if (fdIsUsed[i] && FD_ISSET(transfer_fd[i], &readSet)) {
				bytesRead = read(transfer_fd[i], buffer, BUFFER_SIZE);
				if ( 0 == bytesRead ) {
					close(client_fd[i]);
					close(transfer_fd[i]);
					fdIsUsed[i] = 0;
					clients_count--;
				} else {
					write(client_fd[i], buffer, bytesRead);
				}
			}
		}

		for (int i = 0; i < CONNECTIONS_ALLOWED; i++) {
			if ( fdIsUsed[i] && FD_ISSET(client_fd[i], &readSet) ) {
				bytesRead = read(client_fd[i], buffer, BUFFER_SIZE);
				if ( 0 == bytesRead ) {
					close(client_fd[i]);
					close(transfer_fd[i]);
					fdIsUsed[i] = 0;
					clients_count--;
				} else {
					write(transfer_fd[i], buffer, bytesRead);
				}
			}
		}

		if ( FD_ISSET(server_fd, &readSet) ) {
			printf("Accept connection ...\n");
			if ( clients_count >= CONNECTIONS_ALLOWED ) {
				printf("Too much connections\n");
			} else {
				int index = findUnusedFd(fdIsUsed);
				fdIsUsed[index] = 1;

				client_fd[index] = accept(server_fd, 
							  	  (struct sockaddr *) &client_address, 
							  	   &client_address_size);
				if (((transfer_fd[index] = socket(AF_INET, SOCK_STREAM, 0) )== -1)
					|| 0 != connect( transfer_fd[index], 
								  (struct sockaddr *) &transfer_to_address,
								  sizeof(transfer_to_address))) {
					perror("Could not connect to transfer address\n");
					close(client_fd[index]);
				} else {
					clients_count++;
					if (client_fd[index] > maxFd) {
						maxFd = client_fd[index] + 1;
					}
					if (transfer_fd[index] > maxFd) {
						maxFd = transfer_fd[index] + 1;
					}
				}
			}
		}

	}	


	return 0;
}