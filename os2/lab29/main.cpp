#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
#define PORTION_SIZE 1024
#define BUF_SIZE 65536

#define CACHE_SIZE 1024

#define MAX_CONNECTIONS 10
#define HTTP_PORT 80
#define LISTEN_PORT 5000

//CONNECTION STATES
#define READ_FROM_CLIENT 0
#define WRITE_TO_SERVER  1
#define READ_FROM_SERVER 2
#define WRITE_TO_CLIENT  3


typedef struct {
	size_t size;
	char *data;
} String;

typedef struct {
	String request;
	String answer;
} CacheData;


typedef struct {
	int clientSocket;
	int serverSocket;

	int connectionState;

	size_t bytesInBuffer;
	String request;
	String answer;
	char buffer[BUF_SIZE];
} ConnectionInfo;


CacheData cache[CACHE_SIZE] = {0};


int getFreeFd(const int *fdIsUsed) {
	for (int i = 0; i < MAX_CONNECTIONS; i++) {
		if (!fdIsUsed[i]) {
			return i;
		}
	}
	return -1;
}


int isItGetRequest(String request ) {
	return ((request.size >= 3) &&
	   ('G' == request.data[0]) && 
	   ('E' == request.data[1]) && 
	   ('T' == request.data[2]));
}


void cachePush(String request, String answer) {
	static int cashState = 0;

	CacheData result;
	result.request = request;
	result.answer  = answer;

	if (cache[cashState].request.data != NULL ) {//rewrite
		free(cache[cashState].request.data);
		free(cache[cashState].answer.data);
	}
	cache[cashState] = result;
	cashState = (cashState == CACHE_SIZE) ? (cashState + 1) : 0;
}

int compareStrings(String request1, String request2) {
	if (request1.size != request2.size) {
		return 0;	
	}

	for (int i = 0; i < request1.size; ++i) {
		if (request1.data[i] != request2.data[i]) {
			return 0;
		}
	}

	return 1;
}

int findAnswerInCache(String request) {
	for (int i = 0; i < CACHE_SIZE; i++) {
		if (compareStrings(cache[i].request, request)) {
			printf("Answer is from the cache\n");
			return i;
		} 
	}
	printf("Answer is not found in the cache\n");
	return -1;
}


void refreshOurSets(ConnectionInfo client[], const int sessionIsUsed[], fd_set* readSet, fd_set* writeSet, int our_fd){
	FD_ZERO(readSet);
	FD_ZERO(writeSet);
	FD_SET(our_fd, readSet);

	for (int i = 0; i < MAX_CONNECTIONS; i++) {
		if (sessionIsUsed[i]) {
			switch(client[i].connectionState){
				case READ_FROM_CLIENT:
					FD_SET(client[i].clientSocket, readSet);
					//printf("PUT CLIENT READ\n");
					break;
				case READ_FROM_SERVER:
					FD_SET(client[i].serverSocket, readSet);
					//printf("PUT SERVER READ\n");
					break;
				case WRITE_TO_SERVER:
					FD_SET(client[i].serverSocket, writeSet);
					//printf("PUT SERVER WRITE\n");
					break;
				case WRITE_TO_CLIENT:
					FD_SET(client[i].clientSocket, writeSet);
					//printf("PUT CLIENT WRITE\n");
					break;
				default:
					break;
			}
		}
	}
}


void handleNewConnection(int sessionIsUsed[], ConnectionInfo client[], int* maxFdP,
	struct sockaddr_in cl_addr[], int* addr_size, int our_fd){

	printf("Accept connection ...\n");

	int index = getFreeFd(sessionIsUsed);
	if (-1 == index){
		return;
	}
	sessionIsUsed[index] = 1;
	client[index] = (ConnectionInfo){0};
	client[index].connectionState = READ_FROM_CLIENT;
	client[index].clientSocket = accept(
									our_fd, 
				  	  				(struct sockaddr *) &cl_addr[index],
                                    (socklen_t *) addr_size);
	if (client[index].clientSocket > *maxFdP - 1) {
		*maxFdP = client[index].clientSocket + 1;
	}
}

void updateMaxFd(int *maxFdP, ConnectionInfo client[], const int sessionIsUsed[], int sessionIndex, int our_fd){
	if ((client[sessionIndex].serverSocket == (*maxFdP - 1)) || 
	 (client[sessionIndex].clientSocket == (*maxFdP - 1)) ) {

		*maxFdP = our_fd + 1;
		for (int j = 0; j < MAX_CONNECTIONS; j++) {
			if (sessionIsUsed[j] ) {
				if (*maxFdP - 1 < client[j].serverSocket) {
					*maxFdP = client[j].serverSocket + 1;
				}
				if (*maxFdP - 1 < client[j].clientSocket ) {
					*maxFdP = client[j].clientSocket + 1;
				}
			}
		}
	}
}

char* getPath(char* request, size_t length){
	int start = -1;
	int end   = -1;
	int count = 0;

	for (int i = 3; i < length; ++i){//find ' '
		if (request[i] == ' '){
			start = i + 1;
			break;
		}
	}
	if (start != 4){
		return NULL;
	}
	for (int i = start; i < length; ++i){//find "//""
		if (request[i] == '/'){
			if (++count == 2){
				start = i + 1;
				break;
			}
		}
	}
	if (count != 2){
		return NULL;
	}
	for (int i = start; i < length; ++i){
		if (request[i] == '/'){
			end = i;
			break;
		}
	}
	if (end == -1){
		return NULL;
	}
	char* ret = (char*)malloc(sizeof(char) * (end - start + 1));
	memcpy(ret, request + start, (size_t) (end - start));
	ret[end - start] = '\0';
	return ret;
}


void handleReadFromClient(ConnectionInfo client[], int sessionIsUsed[],int sessionIndex,
							 int* maxFdP, int our_fd){

	ssize_t bytesRead = read( client[sessionIndex].clientSocket,
					      client[sessionIndex].buffer + client[sessionIndex].bytesInBuffer,
					      PORTION_SIZE);
	printf("Bytes Read : %ld\n",bytesRead);
	client[sessionIndex].bytesInBuffer += bytesRead;

	if (!(bytesRead == 0 ||
	 (client[sessionIndex].bytesInBuffer >= 4 &&
		client[sessionIndex].buffer[client[sessionIndex].bytesInBuffer - 1] == '\n' &&
		client[sessionIndex].buffer[client[sessionIndex].bytesInBuffer - 2] == '\r' &&
		client[sessionIndex].buffer[client[sessionIndex].bytesInBuffer - 3] == '\n' &&
		client[sessionIndex].buffer[client[sessionIndex].bytesInBuffer - 4] == '\r'))){
		return;
	}
				
	client[sessionIndex].connectionState = WRITE_TO_SERVER;	
	client[sessionIndex].request.size = client[sessionIndex].bytesInBuffer;
	client[sessionIndex].request.data = (char *)calloc(client[sessionIndex].bytesInBuffer, sizeof(char));
	memcpy(client[sessionIndex].request.data, client[sessionIndex].buffer, client[sessionIndex].bytesInBuffer);

	printf("Request received: \n");
	for (int j = 0; j < client[sessionIndex].bytesInBuffer; ++j) {
		printf("%c", client[sessionIndex].buffer[j]);
	}

	if ( !isItGetRequest(client[sessionIndex].request) ) {
		printf("Do not support this type of message\n");
		printf("Session is over\n");

		sessionIsUsed[sessionIndex] = 0;
		updateMaxFd(maxFdP, client, sessionIsUsed, sessionIndex, our_fd);
		close(client[sessionIndex].clientSocket);
		return;
	}
				
	int index = findAnswerInCache(client[sessionIndex].request);

	if (-1 != index) {//we have an answer in the cache
		client[sessionIndex].connectionState = WRITE_TO_CLIENT;
		client[sessionIndex].answer.size = cache[index].answer.size;
		client[sessionIndex].answer.data = (char *)calloc(cache[index].answer.size, sizeof(char));
		memcpy(client[sessionIndex].answer.data, cache[index].answer.data, cache[index].answer.size);
		//client[sessionIndex].answer.data = cache[index].answer.data;
		client[sessionIndex].bytesInBuffer = client[sessionIndex].answer.size;
		//bytesInBuffer is a special
		//check handleWriteToClient() for details
	}
	else {
		struct sockaddr_in server_addr = {0};
		server_addr.sin_family = AF_INET;
		server_addr.sin_port = htons(HTTP_PORT);
		char* path = getPath(client[sessionIndex].request.data, client[sessionIndex].request.size);
		struct hostent * host_info = gethostbyname(path);
		if(host_info == NULL){
			printf(" gethostbyname() failed\n");
			exit(1);
		}

		memcpy(&server_addr.sin_addr, host_info->h_addr, (size_t) host_info->h_length);
		//server_addr.sin_addr.s_addr = inet_addr(argv[1]);

		client[sessionIndex].serverSocket = socket(AF_INET, SOCK_STREAM, 0);
		if ( *maxFdP - 1 < client[sessionIndex].serverSocket ) {
			*maxFdP = client[sessionIndex].serverSocket + 1;
		}

		if (0 != connect( client[sessionIndex].serverSocket, 
	 					  (struct sockaddr *) &server_addr,
	  					  sizeof(server_addr))
			) {
			perror("Can't connect to server address\n");
			exit(1);
		}
		client[sessionIndex].bytesInBuffer = client[sessionIndex].request.size;
	}

}

void handleReadFromServer(ConnectionInfo* client){
	printf("Receiving answer : \n");

	ssize_t bytesRead = read(client->serverSocket,
						 client->buffer + client->bytesInBuffer,
						 PORTION_SIZE );
	client->bytesInBuffer += bytesRead;

	if (0 == bytesRead) {
		client->connectionState = WRITE_TO_CLIENT;
		client->answer.size = client->bytesInBuffer;
		client->answer.data = (char *)calloc(client->bytesInBuffer, sizeof(char));
		memcpy(client->answer.data, client->buffer, client->bytesInBuffer);

		printf("We recieved an answer : \n");
		for (int j = 0; j < client->answer.size; j++) {
			printf("%c",client->answer.data[j]);
		}
		client->bytesInBuffer = client->answer.size;
		cachePush(client->request, client->answer);
	}
}






void handleWriteToServer(ConnectionInfo* client){
	//in this function bytesInBuffer isn't number of bytes in buffer
	//it is a number of bytes that we need to send
	ssize_t bytesWritten = 0;
	size_t bytesToWrite = PORTION_SIZE;

	if (client->bytesInBuffer <= PORTION_SIZE ) {
		bytesToWrite = client->bytesInBuffer;
	}

	bytesWritten = write(client->serverSocket, 
						 client->request.data + 
						(client->request.size - client->bytesInBuffer),
						  bytesToWrite);
	client->bytesInBuffer -= bytesWritten;
	if (0 == bytesWritten ) {
		client->bytesInBuffer = 0;
	}

	if (client->bytesInBuffer <= 0 ) {
		client->connectionState = READ_FROM_SERVER;
		client->bytesInBuffer = 0;
		printf("Request are sent \n");
		//sleep(2);
	} 
}


void handleWriteToClient(ConnectionInfo *client, int sessionIndex, int sessionIsUsed[], int* maxFdP, int our_fd){
	//in this function bytesInBuffer isn't number of bytes in buffer
	//it is a number of bytes that we need to send
	ssize_t bytesWritten = 0;
	size_t bytesToWrite = PORTION_SIZE;

	if ( client[sessionIndex].bytesInBuffer <= PORTION_SIZE ) {
		bytesToWrite = client[sessionIndex].bytesInBuffer;
	}

	bytesWritten = write(client[sessionIndex].clientSocket,
					     client[sessionIndex].answer.data +
					    (client[sessionIndex].answer.size - client[sessionIndex].bytesInBuffer),
						 bytesToWrite);

	client[sessionIndex].bytesInBuffer -= bytesWritten;
	if ( 0 == bytesWritten )  {
		client[sessionIndex].bytesInBuffer = 0;
	}

	if (client[sessionIndex].bytesInBuffer <= 0 ) {
		printf("We sent our message to the client\n");
		printf("Session is over\n");
		sessionIsUsed[sessionIndex] = 0;
		client[sessionIndex].bytesInBuffer = 0;
		updateMaxFd(maxFdP, client, sessionIsUsed, sessionIndex, our_fd);

		close(client[sessionIndex].clientSocket);
		close(client[sessionIndex].serverSocket);
		printf("\n");
	}
}




int main ( int argc, char ** argv ) {

	int our_fd = 0; 
	ConnectionInfo client[MAX_CONNECTIONS] = {0};
	int sessionIsUsed[MAX_CONNECTIONS] = {0};
	
	struct sockaddr_in our_addr = {0};
	struct sockaddr_in client_addr[MAX_CONNECTIONS] = {0};
	
	
	our_addr.sin_family = AF_INET;
	our_addr.sin_port = htons(LISTEN_PORT);
	

	our_addr.sin_addr.s_addr = INADDR_ANY;
	

	our_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (-1 == our_fd) {
		perror("Can't create socket\n");
		return 1;
	}

	printf("Binding socket ...\n");
	if (0 != bind( our_fd, 
				   (struct sockaddr *) &our_addr, 
				   sizeof(our_addr))
		) {
		perror("Can't bind socket to address\n");
		return 1;
	}

	if (0 != listen(our_fd, MAX_CONNECTIONS)) {
		perror("Can't listen to interface\n");
		return 1;
	}
	
	fd_set readSet;
	fd_set writeSet;
	
	int maxFd = our_fd + 1;
	int client_addr_size = sizeof(struct sockaddr_in);

	
	while (1) {
		refreshOurSets(client, sessionIsUsed, &readSet, &writeSet, our_fd);
		int ret_value = select(maxFd, &readSet, &writeSet, NULL, NULL);
        if (ret_value == -1) return 1;
		if (FD_ISSET(our_fd, &readSet)) {
			handleNewConnection(sessionIsUsed, client, &maxFd,
				client_addr, &client_addr_size, our_fd);
			
		}
		
		for (int i = 0; i < MAX_CONNECTIONS; i++) {
			if (!sessionIsUsed[i]){
				continue;
			}
			switch(client[i].connectionState){
				case READ_FROM_CLIENT:
					if (FD_ISSET(client[i].clientSocket, &readSet) ) {
						handleReadFromClient(client, sessionIsUsed, i,  &maxFd,
						 our_fd);
					}
					break;
				case READ_FROM_SERVER:
					if (FD_ISSET(client[i].serverSocket, &readSet)) {
						handleReadFromServer(&client[i]);				
					}
					break;
				case WRITE_TO_SERVER:
					if (FD_ISSET(client[i].serverSocket, &writeSet)) {
						handleWriteToServer(&client[i]);
					}
					break;
				case WRITE_TO_CLIENT:
					if (FD_ISSET(client[i].clientSocket, &writeSet) ) {
						handleWriteToClient(client, i, sessionIsUsed, &maxFd, our_fd);
					}
					break;
				default:
					break;
			}
		}
	}
}

#pragma clang diagnostic pop