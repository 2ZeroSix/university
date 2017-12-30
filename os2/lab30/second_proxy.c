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
#include <errno.h>

#define PORTION_SIZE (1024*32)
#define BUF_SIZE 65536

#define CACHE_SIZE 128

#define MAX_CONNECTIONS 100
#define HTTP_PORT 80
#define LISTEN_PORT 5001

const char const *content_length_string = "Content-Length: ";
const int content_length_string_length = 16;
//CONNECTION STATES
enum ConnectionState {
    READ_FROM_CLIENT,
    WRITE_TO_SERVER,
    READ_FROM_SERVER,
    WRITE_TO_CLIENT,
    ONLY_WRITE_TO_CLIENT,
    ONLY_READ_FROM_SERVER,
    DONE
};

//CACHE STATES
enum CacheState {
    EMPTY,
    READING_HEAD,
    READING_ANSWER,
    WRITING,
    READY
};

typedef struct {
    size_t size;
    char *data;
} String;

typedef struct {
    String url;
    String answer;

    int numberOfUsers;
    enum CacheState state;
    size_t numberOfRdyBytes;
    pthread_mutex_t mutex;
} CacheData;

typedef struct {
    int clientSocket;
    int serverSocket;

    enum ConnectionState connectionState;

    size_t bytesInBuffer;

    size_t readedFromServerBytes;
    size_t writtenToClientBytes;

    String request;
    String answer;
    char buffer[BUF_SIZE];
} ConnectionInfo;

typedef struct _Clients_struct {
    ConnectionInfo client;
    struct _Clients_struct *next;
    CacheData *cacheNode;
} Clients_struct;



CacheData cache[CACHE_SIZE]               = {0};
Clients_struct* head                      = NULL;

pthread_mutex_t lock_for_cache;
pthread_mutex_t listLock;

int isIt200(char* buffer, ssize_t length){
    int index = -1;
    for (int i = 0; i < length; ++i){
        if (buffer[i] == ' '){
            index = i;
            break;
        }
    }
    if(index < 0){
        printf("IT IS NOT 200(((\n");
        return 0;
    }
    if(length > index + 3 &&
       buffer[index + 1] == '2' &&
       buffer[index + 2] == '0' &&
       buffer[index + 3] == '0'){
        return 1;
    }
    printf("IT IS NOT 200(((\n");
    return 0;
}

void deleteFromList(int clSocket) {
    printf("DELETE FROM LIST\n");
    fflush(stdout);
    Clients_struct *tmp;

    pthread_mutex_lock(&listLock);

    if (head->client.clientSocket == clSocket) {
        tmp = head->next;
        free(head);
        head = tmp;
    } else {
        tmp = head;
        while (tmp->next) {
            if (tmp->next->client.clientSocket == clSocket) {
                Clients_struct *tmp2 = tmp->next->next;
                free(tmp->next);
                tmp->next = tmp2;
                printf("DELETE FROM LIST\n");
                fflush(stdout);
                pthread_mutex_unlock(&listLock);
                return;
            }
            tmp = tmp->next;
        }
    }
    printf("DELETE FROM LIST\n");
    fflush(stdout);
    pthread_mutex_unlock(&listLock);

}



int isItGetRequest(String request ) {
	return ((request.size >= 3) &&
	   ('G' == request.data[0]) && 
	   ('E' == request.data[1]) && 
	   ('T' == request.data[2]));
}


CacheData *findPlaceInCache(char *url) {
    int index = -1;

    for (int i = 0; i < CACHE_SIZE; ++i) {
        pthread_mutex_lock(&cache[i].mutex);
        if (cache[i].state == EMPTY) {
            index = i;
            break;
        }
        pthread_mutex_unlock(&cache[i].mutex);
    }
    if (-1 == index){
        for (int i = 0; i < CACHE_SIZE; ++i) {
            pthread_mutex_lock(&cache[i].mutex);
            if (cache[i].numberOfUsers == 0) {
                if (cache[i].url.data) {
                    free(cache[i].url.data);
                }
                if (cache[i].answer.data) {
                    free(cache[i].answer.data);
                }
                index = i;
                break;
            }
            pthread_mutex_unlock(&cache[i].mutex);
        }
    }
    if (-1 == index){
        return NULL;
    }

    cache[index].url.size = strlen(url) + 1;
    cache[index].url.data = (char *) calloc((strlen(url) + 1), sizeof(char));
    memcpy(cache[index].url.data, url, strlen(url) + 1);

    cache[index].state = WRITING;
    cache[index].numberOfUsers = 1;
    cache[index].numberOfRdyBytes = 0;
    pthread_mutex_unlock(&cache[index].mutex);
    return &cache[index];
}


int compareStrings(String request1, char *url) {
    if (request1.size != strlen(url) + 1) {
        return 0;
    }

    for (int i = 0; i < request1.size; ++i) {
        if (request1.data[i] != url[i]) {
            return 0;
        }
    }

    return 1;
}

Clients_struct* push_new_client(int clientSocket) {
    printf("HI\n");
    fflush(stdout);
    Clients_struct *tmp = (Clients_struct *) calloc(1, sizeof(Clients_struct));
    if (tmp == NULL) {
        perror("HELLO\n");
        fflush(stdout);
        fflush(stderr);
    }

    pthread_mutex_lock(&listLock);
    tmp->client                 = (ConnectionInfo) {0};
    tmp->client.connectionState = READ_FROM_CLIENT;
    tmp->client.clientSocket    = clientSocket;
    tmp->next = head;

    head = tmp;
    pthread_mutex_unlock(&listLock);

    return tmp;
}


CacheData *findAnswerInCache(char *url) {
    for (int i = 0; i < CACHE_SIZE; i++) {
        pthread_mutex_lock(&cache[i].mutex);
        if (cache[i].state != EMPTY) {
            if (compareStrings(cache[i].url, url)) {
                printf("Answer is from the cache\n");
                ++cache[i].numberOfUsers;
                pthread_mutex_unlock(&cache[i].mutex);
                return &cache[i];
            }
        }
        pthread_mutex_unlock(&cache[i].mutex);
    }
    printf("Answer is not found in the cache\n");
    return NULL;
}


char *getPath(char *url) {
    int end = -1;
    int start = -1;

    for (int i = 0; i < strlen(url) - 1; ++i) {
        if (url[i] == '/' && url[i + 1] == '/') {
            start = i + 2;
            break;
        }
    }
    if (start == -1) {
        return NULL;
    }

    for (int i = start; i < strlen(url); ++i) {
        if (url[i] == '/' || url[i] == ':') {
            end = i;
            break;
        }
    }
    if (end == -1) {
        return NULL;
    }

    char *tmp = (char *) calloc((end - start + 1), sizeof(char));
    memcpy(tmp, url + start, end - start);
    tmp[end - start] = '\0';
    printf("%s", tmp);
    return tmp;
}
char *getUrl(char *data, size_t size) {
    int endIndex = -1;
    if (data[3] != ' ') {
        return NULL;
    }

    for (int i = 4; i < size; ++i) {
        if (data[i] == ' ') {
            endIndex = i;
            break;
        }
    }
    char *tmp = (char *) calloc((endIndex - 3), sizeof(char));
    memcpy(tmp, data + 4, (endIndex - 4));
    tmp[endIndex - 4] = '\0';
    return tmp;
}
void handleReadFromClient(Clients_struct* client){

    ssize_t bytesRead = read(client->client.clientSocket,
                             client->client.buffer + client->client.bytesInBuffer,
                             PORTION_SIZE);
    printf("Bytes Read : %ld\n", bytesRead);
    client->client.bytesInBuffer += bytesRead;

//if we need to read more
    if (!(bytesRead == 0 ||
          (client->client.bytesInBuffer >= 4 &&
           client->client.buffer[client->client.bytesInBuffer - 1] == '\n' &&
           client->client.buffer[client->client.bytesInBuffer - 2] == '\r' &&
           client->client.buffer[client->client.bytesInBuffer - 3] == '\n' &&
           client->client.buffer[client->client.bytesInBuffer - 4] == '\r'))) {
        return;
    }

    client->client.connectionState = WRITE_TO_SERVER;
    client->client.request.size = client->client.bytesInBuffer;
    client->client.request.data = (char *) calloc(client->client.bytesInBuffer, sizeof(char));
    memcpy(client->client.request.data, client->client.buffer, client->client.bytesInBuffer);

    client->client.readedFromServerBytes = 0;
    client->client.writtenToClientBytes = 0;

    printf("Request received: \n");
    for (int j = 0; j < client->client.bytesInBuffer; ++j) {
        printf("%c", client->client.buffer[j]);
    }
//if it is not get
    if (!isItGetRequest(client->client.request)) {
        printf("Do not support this type of message\n");
        printf("Session is over\n\n");

        client->client.connectionState = DONE;
        close(client->client.clientSocket);
        return;
    }

    char *url = getUrl(client->client.request.data, client->client.request.size);
    if (url == NULL) {
        close(client->client.clientSocket);
        client->client.connectionState = DONE;
        printf("url == null\n");
        return;
    }

    client->cacheNode = findAnswerInCache(url);//THIS

    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(HTTP_PORT);

    char *path = getPath(url);

    struct hostent *host_info = gethostbyname(path);
    if (host_info == NULL) {
        close(client->client.clientSocket);
        client->client.connectionState = DONE;
        printf("host_info == null\n");
        return;
    }

    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

    client->client.serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    if (0 != connect(client->client.serverSocket,
                     (struct sockaddr *) &server_addr,
                     sizeof(server_addr))
            ) {
        close(client->client.clientSocket);
        client->client.connectionState = DONE;
        return;
    }

    if (NULL != client->cacheNode) {//we have an answer in the cache
        pthread_mutex_lock(&client->cacheNode->mutex);
        switch (client->cacheNode->state) {
            case READY:
                client->client.connectionState = WRITE_TO_CLIENT;
                client->client.answer.size = client->cacheNode->answer.size;
                client->client.bytesInBuffer = client->client.answer.size;
                break;
            default:
                client->client.connectionState = WRITE_TO_SERVER;
                client->client.bytesInBuffer = client->client.request.size;
                break;
        }
        pthread_mutex_unlock(&client->cacheNode->mutex);
    } else {
        client->cacheNode = findPlaceInCache(url);
        client->client.bytesInBuffer = client->client.request.size;
    }

}

ssize_t getLengthFromAnswer(char buffer[], size_t bodyStart) {
    // "Content-Length: " - our goal
    ssize_t found = -1;
    size_t count = 0;
    for (size_t i = 0; i < bodyStart - content_length_string_length; ++i) {
        for (int j = 0; j < content_length_string_length; ++j) {
            if (buffer[i + j] != content_length_string[j]) {
                count = 0;
                break;
            } else {
                count++;
            }
        }
        if (count == content_length_string_length) {
            found = i + content_length_string_length;
            break;
        }
    }
    //printf("FOUND = %d\n", found);
    if (found < 0)
        return bodyStart;
    ssize_t bodyLength = atoll(buffer + found);
    if (bodyLength > 0) {
        return bodyStart + bodyLength;
    } else {
        return -1;
    }

}

ssize_t headIsOver(char buffer[], size_t length) {
    for (ssize_t i = 0; i < length - 3; ++i) {
        if ('\r' == buffer[i] &&
            '\n' == buffer[i + 1] &&
            '\r' == buffer[i + 2] &&
            '\n' == buffer[i + 3]) {
            //printf("2 LAST SYMBOLS %c%c\n", buffer[i - 1], buffer[i - 2]);
            return i + 4;
        }
    }
    return -1;
}

void copyArr(char *buffer, char *cacheData, size_t bufStart, size_t bufEnd, size_t cacheStart) {
    printf("\n%lu : %lu : %lu\n", bufStart, bufEnd, cacheStart);
    fflush(stdout);
    for (int i = 0; i <= bufEnd - bufStart; ++i) {
        cacheData[cacheStart + i] = buffer[bufStart + i];
    }
}

void handleReadFromServer(Clients_struct *client) {
    printf("Receiving answer : \n");
    int size_for_read = PORTION_SIZE;
    size_for_read = BUF_SIZE - client->client.bytesInBuffer;
    size_for_read = (size_for_read > PORTION_SIZE) ? PORTION_SIZE : size_for_read;

    int bytesRead = read(client->client.serverSocket,
                         client->client.buffer + client->client.bytesInBuffer,
                         size_for_read);
    printf("GOT %d BYTES FROM SERVER\n", bytesRead);
    if (bytesRead == 0) {
        client->client.connectionState = WRITE_TO_CLIENT;
        return;
    }
    /*printf("CHECK THEM\n");
    for (int i = client->client.bytesInBuffer; i < client->client.bytesInBuffer + bytesRead; ++i){
        printf("%c", client->client.buffer[i]);
    }
    printf("ITS ALL\n\n");*/

    client->client.readedFromServerBytes += bytesRead;
    client->client.bytesInBuffer += bytesRead;
    ssize_t flag;
    if (client->cacheNode) {
        pthread_mutex_lock(&client->cacheNode->mutex);
        switch (client->cacheNode->state) {
            case READY:
                printf("CASE READY\n");
                close(client->client.serverSocket);
                client->client.connectionState = WRITE_TO_CLIENT;
                client->client.answer.size = client->cacheNode->answer.size;
                client->client.bytesInBuffer = client->client.answer.size;
                pthread_mutex_unlock(&client->cacheNode->mutex);
                return;
            case READING_HEAD:

                flag = headIsOver(client->client.buffer, client->client.readedFromServerBytes);
                printf("CASE READING HEAD. FLAG = %ld\n", flag);
                if (flag > 0) {//if head is readed
                    if (!isIt200(client->client.buffer, flag)) {
                        client->cacheNode->numberOfUsers -= 1;
                        if (client->cacheNode->numberOfUsers == 0) {
                            client->cacheNode->state = EMPTY;
                        }
                        pthread_mutex_unlock(&client->cacheNode->mutex);
                        client->cacheNode = NULL;
                        if (client->client.bytesInBuffer == BUF_SIZE){
                            client->client.connectionState = ONLY_WRITE_TO_CLIENT;
                        }
                        break;
                    }
                    if ((flag = getLengthFromAnswer(client->client.buffer, flag))) {
                        if (flag < client->client.readedFromServerBytes) {
                            printf("HTTP 1.1 CANT HANDLE THAT. WE ARE GOING ON WITHOUT CACHE\n");
                            client->cacheNode->numberOfUsers -= 1;
                            if (client->cacheNode->numberOfUsers == 0) {
                                client->cacheNode->state = EMPTY;
                            }
                            pthread_mutex_unlock(&client->cacheNode->mutex);
                            client->cacheNode = NULL;
                            if (client->client.bytesInBuffer == BUF_SIZE){
                                client->client.connectionState = ONLY_WRITE_TO_CLIENT;
                            }
                            break;
                        }
//                        printf("%.*s", client->client.bytesInBuffer, client->client.buffer);
                        printf("FLAG: %ld", flag);
                        client->client.bytesInBuffer = 0;//WE NEED IT TO WRITE DATE IN THE BEGINING OF BUF
                        client->cacheNode->state = READING_ANSWER;
                        client->cacheNode->answer.data = (char *) calloc(flag, sizeof(char));
                        client->cacheNode->answer.size = (size_t) flag;
                        client->cacheNode->numberOfRdyBytes = client->client.readedFromServerBytes;
                        copyArr(client->client.buffer, client->cacheNode->answer.data, 0,
                                client->client.readedFromServerBytes - 1, 0);

                        //if this is the end
                        if (client->cacheNode->numberOfRdyBytes == client->cacheNode->answer.size) {
                            close(client->client.serverSocket);
                            client->cacheNode->state = READY;
                            client->client.connectionState = WRITE_TO_CLIENT;
                            client->client.answer.size = client->cacheNode->answer.size;
                            client->client.bytesInBuffer = client->client.answer.size;

                            printf("We recieved an answer : \n");
//                            for (int j = 0; j < client->cacheNode->answer.size; j++) {
//                                printf("%c", client->cacheNode->answer.data[j]);
//                            }
                            pthread_mutex_unlock(&client->cacheNode->mutex);
                            return;
                        }
                    } else {//cant calculate length
                        printf("can't calculate answer's length\n");
                        close(client->client.serverSocket);
                        close(client->client.clientSocket);
                        //HERE WE NEED TO DELETE
                        exit(1);
                    }
                } else {//have not readed head yet
                    pthread_mutex_unlock(&client->cacheNode->mutex);
                    return;
                }
                pthread_mutex_unlock(&client->cacheNode->mutex);
                break;
            case READING_ANSWER:
                printf("CASE READING_ANSWER\n");
                client->client.bytesInBuffer = 0;//WE NEED IT TO WRITE A DATE IN THE BEGINING OF BUF
                ssize_t diff = client->client.readedFromServerBytes - client->cacheNode->numberOfRdyBytes;
                if (diff > 0) {
                    copyArr(client->client.buffer, client->cacheNode->answer.data, bytesRead - diff, bytesRead - 1,
                            client->cacheNode->numberOfRdyBytes);
                    client->cacheNode->numberOfRdyBytes += diff;
                    //if this is the end
                    if (client->cacheNode->numberOfRdyBytes == client->cacheNode->answer.size) {
                        close(client->client.serverSocket);
                        client->cacheNode->state = READY;
                        client->client.connectionState = WRITE_TO_CLIENT;
                        client->client.answer.size = client->cacheNode->answer.size;
                        client->client.bytesInBuffer = client->client.answer.size;

                        printf("We recieved an answer : \n");
                        for (int j = 0; j < client->cacheNode->answer.size; j++) {
                            printf("%c", client->cacheNode->answer.data[j]);
                        }

                        pthread_mutex_unlock(&client->cacheNode->mutex);
                        return;
                    }
                }
                pthread_mutex_unlock(&client->cacheNode->mutex);
                break;
            default:
                pthread_mutex_unlock(&client->cacheNode->mutex);
                break;
        }
    } else {//no cache
        if (bytesRead == 0){
            client->client.connectionState = WRITE_TO_CLIENT;
        }
        if (client->client.bytesInBuffer == BUF_SIZE){
            client->client.connectionState = ONLY_WRITE_TO_CLIENT;
        }
    }
}



void handleWriteToServer(Clients_struct* client){
    int bytesWritten = 0;
    int bytesToWrite = PORTION_SIZE;

    if (client->client.bytesInBuffer <= PORTION_SIZE) {
        bytesToWrite = client->client.bytesInBuffer;
    }

    bytesWritten = write(client->client.serverSocket,
                         client->client.request.data +
                         (client->client.request.size - client->client.bytesInBuffer),
                         bytesToWrite);
    client->client.bytesInBuffer -= bytesWritten;
    if (0 == bytesWritten) {
        client->client.bytesInBuffer = 0;
    }


    if (client->client.bytesInBuffer <= 0) {
        if (client->cacheNode) {
            pthread_mutex_lock(&client->cacheNode->mutex);
            switch (client->cacheNode->state) {
                case READY:
                    close(client->client.serverSocket);
                    client->client.connectionState = WRITE_TO_CLIENT;
                    client->client.answer.size = client->cacheNode->answer.size;
                    client->client.bytesInBuffer = client->client.answer.size;
                    break;
                case WRITING:
                    client->cacheNode->state = READING_HEAD;
                    client->client.bytesInBuffer = 0;
                    client->client.connectionState = READ_FROM_SERVER;
                    break;
                default:
                    client->client.connectionState = READ_FROM_SERVER;
                    client->client.bytesInBuffer = 0;
                    break;
            }
            pthread_mutex_unlock(&client->cacheNode->mutex);
        } else{
            client->client.bytesInBuffer = 0;
            client->client.connectionState = READ_FROM_SERVER;
        }
        printf("Request are sent \n");
    }
}


void handleWriteToClient(Clients_struct *client) {
    //in this function bytesInBuffer isn't number of bytes in buffer
    //it is a number of bytes that we need to send
    int bytesWritten = 0;
    size_t bytesToWrite = PORTION_SIZE;

    char *source;
    size_t shift;
    if (client->cacheNode) {
        pthread_mutex_lock(&client->cacheNode->mutex);
        switch (client->cacheNode->state) {
            case READY:
                source = client->cacheNode->answer.data;
                shift = client->client.writtenToClientBytes;
                bytesToWrite = client->cacheNode->answer.size - shift;
                break;
            case READING_ANSWER:
                source = client->cacheNode->answer.data;
                shift = client->client.writtenToClientBytes;
                bytesToWrite = client->cacheNode->numberOfRdyBytes - shift;
                break;
            case READING_HEAD:
                source = client->client.buffer;
                shift = client->client.writtenToClientBytes;
                bytesToWrite = client->client.bytesInBuffer - shift;
                break;
            default:
                pthread_mutex_unlock(&client->cacheNode->mutex);
                return;
        }
        bytesToWrite = (bytesToWrite > PORTION_SIZE) ? PORTION_SIZE : bytesToWrite;
//        printf("%.*s", bytesToWrite,source + shift);
        errno = 0;
        int bytesWritten = write(client->client.clientSocket, source + shift, bytesToWrite);
        if (errno != 0) {
            int clSocket = client->client.clientSocket;
            int svSocket = client->client.serverSocket;

            close(clSocket);
            client->client.connectionState = DONE;
            perror("Error");
            pthread_mutex_unlock(&client->cacheNode->mutex);
            return;
        }
        client->client.writtenToClientBytes += bytesWritten;

        switch (client->cacheNode->state) {
            case READING_HEAD:
                pthread_mutex_unlock(&client->cacheNode->mutex);
                return;
            default:
                if (client->client.writtenToClientBytes == client->cacheNode->answer.size) {
                    printf("We sent our message to the client\n");
                    printf("Session is over\n");

                    client->cacheNode->numberOfUsers -= 1;
                    int clSocket = client->client.clientSocket;
                    int svSocket = client->client.serverSocket;


                    close(clSocket);
                    client->client.connectionState = DONE;
                    printf("\n");
                }
        }
        pthread_mutex_unlock(&client->cacheNode->mutex);
    } else {
        source = client->client.buffer;
        shift = (int) (client->client.writtenToClientBytes % BUF_SIZE);
        bytesToWrite = (int) (client->client.bytesInBuffer - shift > PORTION_SIZE ? PORTION_SIZE : client->client.bytesInBuffer - shift);

//        printf("%.*s", bytesToWrite,source + shift);
        int bytesWritten = write(client->client.clientSocket, source + shift, bytesToWrite);
        client->client.writtenToClientBytes += bytesWritten;
        if (bytesWritten < 0) {
//HANDLE MISTAKE
        }
        if (client->client.connectionState == WRITE_TO_CLIENT && bytesWritten == 0) {
            printf("We sent our message to the client\n");
            printf("Session is over\n");
            int clSocket = client->client.clientSocket;
            int svSocket = client->client.serverSocket;

            close(clSocket);
            client->client.connectionState = DONE;
            return;
        }

        if (client->client.connectionState == ONLY_WRITE_TO_CLIENT &&
            client->client.writtenToClientBytes % BUF_SIZE == 0) {
            client->client.connectionState = READ_FROM_SERVER;
            client->client.bytesInBuffer = 0;
        }
    }
}


void* childBody(void* p){
	Clients_struct* client = (Clients_struct*)p;
	
	while(1){
		switch(client->client.connectionState){
			case READ_FROM_CLIENT:
				handleReadFromClient(client);
				break;
			case WRITE_TO_SERVER:
				handleWriteToServer(client);
				break;
			case READ_FROM_SERVER:
				handleReadFromServer(client);
				handleWriteToClient(client);
				break;
			case ONLY_WRITE_TO_CLIENT:
			case WRITE_TO_CLIENT:
				handleWriteToClient(client);
				break;
			case DONE:
                if (client->cacheNode) {
                    pthread_mutex_lock(&client->cacheNode->mutex);
                    --client->cacheNode->numberOfUsers;
                    pthread_mutex_unlock(&client->cacheNode->mutex);
                }
                free(client->client.request.data);
                client->client.request.data = NULL;
                free(client->client.answer.data);
                client->client.answer.data = NULL;
				deleteFromList(client->client.clientSocket);
				pthread_exit(NULL);
				break;
		}
	}	
}


int main ( int argc, char ** argv ) {
	int our_fd = 0;

	if (pthread_mutex_init (&listLock, NULL) != 0){
        printf("mutex init error\n");
        exit(1);
	}
	if (pthread_mutex_init (&lock_for_cache, NULL) != 0){
        printf("mutex init error\n");
        pthread_mutex_destroy(&listLock);
        exit(1);
	}
    for (int i = 0; i < CACHE_SIZE; ++i){
        if (pthread_mutex_init (&cache[i].mutex, NULL) != 0){
            printf("mutex init error\n");
            for (int j = 0; j < i; ++j){
                pthread_mutex_destroy(&cache[i].mutex);
            }
            exit(1);
        }
    }

	struct sockaddr_in our_addr = {0};
	
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
	
	
	
	int client_addr_size = sizeof(struct sockaddr_in);
	int *tmpSocketP = (int*)calloc(1, sizeof(int));
	struct sockaddr_in client_addr_tmp = {0};
	while (1) {
		*tmpSocketP = accept(our_fd, 
				  	  		 (struct sockaddr *) &client_addr_tmp, 
				  	   		  &client_addr_size);
		printf("New connection ...\n");

		
		Clients_struct* new_client = push_new_client(*tmpSocketP);
		
		pthread_t thread;

		if (pthread_create(&thread, NULL, childBody, new_client) != 0){
        	printf("thread problem\n");
        	//don't know what to do here
        	exit(1);
    	}
        pthread_detach(thread);

	}

	return 0;
}