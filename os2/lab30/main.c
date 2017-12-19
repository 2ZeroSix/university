#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <pthread.h>

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
#define DONE             4

typedef struct {
	int size;
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

	int bytesInBuffer;
	String request;
	String answer;
	char buffer[BUF_SIZE];
} ConnectionInfo;


CacheData cache[CACHE_SIZE]               = {0};
ConnectionInfo clientArr[MAX_CONNECTIONS] = {0};
int sessionIsUsedArr[MAX_CONNECTIONS]     = {0};

int NUMBER_OF_THREADS_IN_PROCESS          = 0;
pthread_mutex_t lock_for_cache;
pthread_mutex_t lock_for_threads_number;
pthread_cond_t  cond_for_threads_number;


int getFreeFd(int *fdIsUsed) {
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
	pthread_mutex_lock(&lock_for_cache);

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

	pthread_mutex_unlock(&lock_for_cache);
	return;
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
	pthread_mutex_lock(&lock_for_cache);

	for (int i = 0; i < CACHE_SIZE; i++) {
		if (compareStrings(cache[i].request, request)) {
			printf("Answer is from the cache\n");
			pthread_mutex_unlock(&lock_for_cache);
			return i;
		} 
	}
	printf("Answer is not found in the cache\n");

	pthread_mutex_unlock(&lock_for_cache);
	return -1;
}

char* getPath(char* request, int length){
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
	memcpy(ret, request + start, (end - start));
	ret[end - start] = '\0';
	return ret;
}

void handleReadFromClient(ConnectionInfo client[], int sessionIndex){
	//printf("BEFORE READ %d\n", sessionIndex);

	int bytesRead = read( client[sessionIndex].clientSocket, 
					      client[sessionIndex].buffer + client[sessionIndex].bytesInBuffer,
					      PORTION_SIZE);
	printf("Bytes Read : %d\n",bytesRead);
	client[sessionIndex].bytesInBuffer += bytesRead;

	//is it end or not? \r\n\r\n 
	if (!(bytesRead == 0 ||
	 (client[sessionIndex].bytesInBuffer >= 4 &&
		client[sessionIndex].buffer[client[sessionIndex].bytesInBuffer - 1] == '\n' &&
		client[sessionIndex].buffer[client[sessionIndex].bytesInBuffer - 2] == '\r' &&
		client[sessionIndex].buffer[client[sessionIndex].bytesInBuffer - 3] == '\n' &&
		client[sessionIndex].buffer[client[sessionIndex].bytesInBuffer - 4] == '\r'))){
		return;
	}
	else if(bytesRead < 0){
		printf("readed -1 from client. Im out\n");
		client[sessionIndex].connectionState = DONE;
		close(client[sessionIndex].clientSocket);
	}
	//copy from buffer			
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

		client[sessionIndex].connectionState = DONE;
		close(client[sessionIndex].clientSocket);
		return;
	}
				
	int index = findAnswerInCache(client[sessionIndex].request);

	if (-1 != index) {//we have an answer in the cache
		client[sessionIndex].connectionState = WRITE_TO_CLIENT;
		client[sessionIndex].answer.size = cache[index].answer.size;
		client[sessionIndex].answer.data = (char *)calloc(cache[index].answer.size, sizeof(char));
		memcpy(client[sessionIndex].answer.data, cache[index].answer.data, cache[index].answer.size);
		client[sessionIndex].bytesInBuffer = client[sessionIndex].answer.size;
		//bytesInBuffer is a special
		//check handleWriteToClient() for details
	}
	else {
		struct sockaddr_in server_addr = {0};
		server_addr.sin_family         = AF_INET;
		server_addr.sin_port           = htons(HTTP_PORT);

		char* path = getPath(client[sessionIndex].request.data, client[sessionIndex].request.size);
		struct hostent * host_info = gethostbyname(path);
		if(host_info == NULL){
			printf(" gethostbyname() failed\n");
			client[sessionIndex].connectionState = DONE;
			close(client[sessionIndex].clientSocket);
			return;
		}

		memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

		client[sessionIndex].serverSocket = socket(AF_INET, SOCK_STREAM, 0);

		if (0 != connect(client[sessionIndex].serverSocket, 
	 					 (struct sockaddr *) &server_addr,
	  					 sizeof(server_addr))
			) {
			printf("Can't connect to the server. Im out\n");
			client[sessionIndex].connectionState = DONE;
			close(client[sessionIndex].clientSocket);
			return;
		}
		client[sessionIndex].bytesInBuffer = client[sessionIndex].request.size;
	}

}

void handleReadFromServer(ConnectionInfo* client){
	printf("Receiving answer : \n");

	int bytesRead = read(client->serverSocket, 
						 client->buffer + client->bytesInBuffer,
						 PORTION_SIZE );
	client->bytesInBuffer += bytesRead;

	if (bytesRead == 0 ||
	 (client->bytesInBuffer >= 4 &&
		client->buffer[client->bytesInBuffer - 1] == '\n' &&
		client->buffer[client->bytesInBuffer - 2] == '\r' &&
		client->buffer[client->bytesInBuffer - 3] == '\n' &&
		client->buffer[client->bytesInBuffer - 4] == '\r')) {

		client->connectionState = WRITE_TO_CLIENT;
		client->answer.size = client->bytesInBuffer;
		client->answer.data = (char *)calloc(client->bytesInBuffer, sizeof(char));
		memcpy(client->answer.data, client->buffer, client->bytesInBuffer);

		printf("We recieved an answer : \n");
		for (int j = 0; j < client->answer.size; j++) {
			printf("%c", client->answer.data[j]);
		}
		client->bytesInBuffer = client->answer.size;
		cachePush(client->request, client->answer);
	}
	else if (bytesRead == -1){
		printf("Readed -1 from server. Im done. \n");
		close(client->clientSocket);
		close(client->serverSocket);
		client->connectionState = DONE;
		return;
	}

}


void handleWriteToServer(ConnectionInfo* client){
	//in this function bytesInBuffer isn't number of bytes in buffer
	//it is a number of bytes that we need to send
	int bytesWritten = 0;
	int bytesToWrite = PORTION_SIZE;

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
	else if(-1 == bytesWritten){
		printf("-1 written to server\n");
		client->connectionState = DONE;
		close(client->clientSocket);
		close(client->serverSocket);
		return;
	}

	if (client->bytesInBuffer <= 0 ) {
		client->connectionState = READ_FROM_SERVER;
		client->bytesInBuffer = 0;
		printf("Request are sent \n");
		//sleep(2);
	} 
}


void handleWriteToClient(ConnectionInfo *client, int sessionIndex){
	//in this function bytesInBuffer isn't number of bytes in buffer
	//it is a number of bytes that we need to send
	int bytesWritten = 0;
	int bytesToWrite = PORTION_SIZE;

	if (client[sessionIndex].bytesInBuffer <= PORTION_SIZE ) {
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
	else if(-1 == bytesWritten){
		printf("-1 written to client\n");
		client[sessionIndex].connectionState = DONE;
		close(client[sessionIndex].clientSocket);
		close(client[sessionIndex].serverSocket);
		return;
	}

	if (client[sessionIndex].bytesInBuffer <= 0 ) {
		printf("We sent our message to the client\n");
		printf("Session is over\n");
		client[sessionIndex].connectionState = DONE;
		client[sessionIndex].bytesInBuffer = 0;
		close(client[sessionIndex].clientSocket);
		close(client[sessionIndex].serverSocket);
		printf("\n");
	}
}


void* childBody(void* p){
	int* my_index = (int*)p;
	//printf("YO YO YO. MY INDEX = %d\n", *my_index);
	while(1){
		
		switch(clientArr[*my_index].connectionState){
			case READ_FROM_CLIENT:
				//printf("YO YO YO. MY INDEX = %d. BEFORE R_F_C\n", *my_index);
				handleReadFromClient(clientArr, *my_index);
				break;
			case WRITE_TO_SERVER:
				handleWriteToServer(&clientArr[*my_index]);
				break;
			case READ_FROM_SERVER:
				handleReadFromServer(&clientArr[*my_index]);
				break;
			case WRITE_TO_CLIENT:
				handleWriteToClient(clientArr, *my_index);
				break;
			case DONE:
				//printf("YO YO YO. MY INDEX = %d. IM DONE\n", *my_index);
				pthread_mutex_lock(&lock_for_threads_number);
				sessionIsUsedArr[*my_index] = 0;
				NUMBER_OF_THREADS_IN_PROCESS--;
				pthread_cond_signal (&cond_for_threads_number);

				if (clientArr[*my_index].request.data){
					free(clientArr[*my_index].request.data);
				}
				if (clientArr[*my_index].answer.data){
					free(clientArr[*my_index].answer.data);
				}

				pthread_mutex_unlock(&lock_for_threads_number);

				pthread_exit(NULL);
				break;
		}
	}	
}


int main ( int argc, char ** argv ) {
	int our_fd = 0;

	if (pthread_mutex_init (&lock_for_threads_number, NULL) != 0){
        printf("mutex init error\n");
        exit(1);
	}
	if (pthread_mutex_init (&lock_for_cache, NULL) != 0){
        printf("mutex init error\n");
        pthread_mutex_destroy(&lock_for_threads_number);
        exit(1);
	}
	if (pthread_cond_init (&cond_for_threads_number, NULL) != 0){
        printf("mutex cond error\n");
        pthread_mutex_destroy(&lock_for_threads_number);
        pthread_mutex_destroy(&lock_for_cache);
        exit(1);
    } 

    pthread_t threads[MAX_CONNECTIONS];
	int indexArr[MAX_CONNECTIONS];
	for (int i = 0; i < MAX_CONNECTIONS; ++i){
		indexArr[i] = i;
	}

	struct sockaddr_in our_addr = {0};
	struct sockaddr_in client_addr[MAX_CONNECTIONS] = {0};
	
	
	our_addr.sin_family      = AF_INET;
	our_addr.sin_port        = htons(LISTEN_PORT);
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
	
	
	
	int maxFd = our_fd + 1;

	int freeIndex;
	int client_addr_size = sizeof(struct sockaddr_in);
	int *tmpSocketP = (int*)malloc(sizeof(int));
	struct sockaddr_in client_addr_tmp = {0};
	while (1) {
		*tmpSocketP = accept(our_fd, 
				  	  		 (struct sockaddr *) &client_addr_tmp, 
				  	   		  &client_addr_size);
		printf("New connection ...\n");
		pthread_mutex_lock(&lock_for_threads_number);
		while (NUMBER_OF_THREADS_IN_PROCESS == MAX_CONNECTIONS){
			pthread_cond_wait(&cond_for_threads_number, &lock_for_threads_number);
		}
		freeIndex = getFreeFd(sessionIsUsedArr);
		pthread_mutex_unlock(&lock_for_threads_number);
		if (-1 == freeIndex){
			printf("something strange is happening. index == -1\n");
			continue;
		}
		sessionIsUsedArr[freeIndex]          = 1;
		clientArr[freeIndex]                 = (ConnectionInfo){0};
		clientArr[freeIndex].clientSocket    = *tmpSocketP;
		clientArr[freeIndex].connectionState = READ_FROM_CLIENT;

		if (pthread_create(threads + freeIndex, NULL, childBody, indexArr + freeIndex) != 0){
        	printf("thread problem\n");
        	//don't know what to do here
        	exit(1);
    	}

	}

	return 0;
}