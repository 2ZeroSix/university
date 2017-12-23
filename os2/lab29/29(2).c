#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string.h>
#include <stddef.h>
#include <tgmath.h>

#define PORTION_SIZE (1024*32)
#define BUF_SIZE 65536

#define CACHE_SIZE 128

#define MAX_CONNECTIONS 100
#define HTTP_PORT 80
#define LISTEN_PORT 5001

//CONNECTION STATES
#define READ_FROM_CLIENT 0
#define WRITE_TO_SERVER  1
#define READ_FROM_SERVER 2
#define WRITE_TO_CLIENT  3
#define ONLY_WRITE_TO_CLIENT 4
#define ONLY_READ_FROM_SERVER 5
//CACHE STATES
#define EMPTY            0
#define READING_HEAD     1
#define READING_ANSWER   2
#define WRITING          3
#define READY            4


typedef struct {
    size_t size;
    char *data;
} String;

typedef struct {
    String url;
    String answer;

    int numberOfUsers;
    int state;
    size_t numberOfRdyBytes;
} CacheData;

typedef struct {
    int clientSocket;
    int serverSocket;

    int connectionState;

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

char *content_length_string = "Content-Length: ";
int content_length_string_length = 16;


CacheData cache[CACHE_SIZE] = {0};

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

void deleteFromList(Clients_struct **head, int clSocket) {
    printf("DELETE FROM LIST\n");
    fflush(stdout);
    Clients_struct *tmp;


    if ((*head)->client.clientSocket == clSocket) {
        tmp = (*head)->next;
        free(*head);
        *head = tmp;
    } else {
        tmp = *head;
        while (tmp->next) {
            if (tmp->next->client.clientSocket == clSocket) {
                Clients_struct *tmp2 = tmp->next->next;
                free(tmp->next);
                tmp->next = tmp2;
                printf("DELETE FROM LIST\n");
                fflush(stdout);
                return;
            }
            tmp = tmp->next;
        }
    }
    printf("DELETE FROM LIST\n");
    fflush(stdout);
}

int isItGetRequest(String request) {
    return ((request.size >= 3) &&
            ('G' == request.data[0]) &&
            ('E' == request.data[1]) &&
            ('T' == request.data[2]));
}

CacheData *findPlaceInCache() {
    for (int i = 0; i < CACHE_SIZE; ++i) {
        if (cache[i].state == EMPTY) {
            return &cache[i];
        }
    }
    for (int i = 0; i < CACHE_SIZE; ++i) {
        if (cache[i].numberOfUsers == 0) {
            if (cache[i].url.data) {
                free(cache[i].url.data);
            }
            if (cache[i].answer.data) {
                free(cache[i].answer.data);
            }
            return &cache[i];
        }
    }
    return NULL;
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

CacheData *findAnswerInCache(char *url) {
    for (int i = 0; i < CACHE_SIZE; i++) {
        if (cache[i].state != EMPTY) {
            if (compareStrings(cache[i].url, url)) {
                printf("Answer is from the cache\n");
                return &cache[i];
            }
        }
    }
    printf("Answer is not found in the cache\n");
    return NULL;
}


void refreshOurSets(Clients_struct *client, fd_set *readSet, fd_set *writeSet, int our_fd) {
    FD_ZERO(readSet);
    FD_ZERO(writeSet);
    FD_SET(our_fd, readSet);

    while (client) {
        switch (client->client.connectionState) {
            case READ_FROM_CLIENT:
                FD_SET(client->client.clientSocket, readSet);
//printf("PUT CLIENT READ\n");
                break;
            case ONLY_READ_FROM_SERVER:
                FD_SET(client->client.serverSocket, readSet);
                break;
            case ONLY_WRITE_TO_CLIENT:
                FD_SET(client->client.clientSocket, writeSet);
                break;
            case READ_FROM_SERVER:
                FD_SET(client->client.serverSocket, readSet);
                FD_SET(client->client.clientSocket, writeSet);
//printf("PUT SERVER READ\n");
//printf("PUT CLIENT WRITE\n");
                break;
            case WRITE_TO_SERVER:
                FD_SET(client->client.serverSocket, writeSet);
//printf("PUT SERVER WRITE\n");
                break;
            case WRITE_TO_CLIENT:
                FD_SET(client->client.clientSocket, writeSet);
//printf("PUT CLIENT WRITE\n");
                break;
            default:
                break;
        }
        client = client->next;
    }
}

void push_new_client(Clients_struct **client, int clientSocket) {
    printf("HI\n");
    fflush(stdout);
    Clients_struct *tmp = (Clients_struct *) malloc(sizeof(Clients_struct));
    if (tmp == NULL) {
        perror("HELLO\n");
        fflush(stdout);
        fflush(stderr);
    }
    tmp->client = (ConnectionInfo) {0};
    tmp->client.connectionState = READ_FROM_CLIENT;
    tmp->client.clientSocket = clientSocket;
    tmp->next = (*client);

    (*client) = tmp;
}

void handleNewConnection(Clients_struct **client, int *maxFdP, int our_fd) {

    if (!client) {
        printf("somehow adress to Clients_struct is NULL\n");
        return;
    }
    printf("Accept connection ...\n");

    struct sockaddr_in cl_addr = {0};
    int client_addr_size = sizeof(struct sockaddr_in);

    int clientSocket = accept(
            our_fd,
            (struct sockaddr *) &cl_addr,
            &client_addr_size);
    if (clientSocket > *maxFdP - 1) {
        *maxFdP = clientSocket + 1;
    }
    push_new_client(client, clientSocket);
}

void updateMaxFd(int *maxFdP, Clients_struct *client, int clSocket, int svSocket, int our_fd) {
    if ((svSocket == (*maxFdP - 1)) || (clSocket == (*maxFdP - 1))) {
        *maxFdP = our_fd + 1;

        while (client) {
            if (*maxFdP - 1 < client->client.serverSocket) {
                *maxFdP = client->client.serverSocket + 1;
            }
            if (*maxFdP - 1 < client->client.clientSocket) {
                *maxFdP = client->client.clientSocket + 1;
            }
            client = client->next;
        }
    }
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

    char *tmp = (char *) malloc((end - start + 1) * sizeof(char));
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
    char *tmp = (char *) malloc(sizeof(char) * (endIndex - 3));
    memcpy(tmp, data + 4, (endIndex - 4));
    tmp[endIndex - 4] = '\0';
    return tmp;
}

void handleReadFromClient(Clients_struct **fullList, Clients_struct *client,
                          int *maxFdP, int our_fd) {

    ssize_t bytesRead = read(client->client.clientSocket,
                             client->client.buffer + client->client.bytesInBuffer,
                             PORTION_SIZE);
    printf("Bytes Read : %ld\n", bytesRead);
    client->client.bytesInBuffer += bytesRead;

    //if we need to read more
    if (!(bytesRead == 0 /*||
          (client->client.bytesInBuffer >= 4 &&
           client->client.buffer[client->client.bytesInBuffer - 1] == '\n' &&
           client->client.buffer[client->client.bytesInBuffer - 2] == '\r' &&
           client->client.buffer[client->client.bytesInBuffer - 3] == '\n' &&
           client->client.buffer[client->client.bytesInBuffer - 4] == '\r')*/)) {
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

        int clSocket = client->client.clientSocket;
        int svSocket = client->client.serverSocket;
        deleteFromList(fullList, clSocket);
        updateMaxFd(maxFdP, *fullList, clSocket, svSocket, our_fd);
        close(clSocket);
        return;
    }

    char *url = getUrl(client->client.request.data, client->client.request.size);
    if (url == NULL) {
        printf("can't find URL\n");
        exit(1);
    }

    client->cacheNode = findAnswerInCache(url);

    if (NULL != client->cacheNode) {//we have an answer in the cache
        client->cacheNode->numberOfUsers += 1;
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
    } else {
        struct sockaddr_in server_addr = {0};
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(HTTP_PORT);

        char *path = getPath(url);

        struct hostent *host_info = gethostbyname(path);
        if (host_info == NULL) {
            printf(" gethostbyname() failed\n");
            exit(1);
        }

        memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

        client->client.serverSocket = socket(AF_INET, SOCK_STREAM, 0);
        if (*maxFdP - 1 < client->client.serverSocket) {
            *maxFdP = client->client.serverSocket + 1;
        }

        if (0 != connect(client->client.serverSocket,
                         (struct sockaddr *) &server_addr,
                         sizeof(server_addr))
                ) {
            printf("Can't connect to server address\n");
            exit(1);
        }
        client->cacheNode = findPlaceInCache();
        if (client->cacheNode) {
            client->cacheNode->url.size = strlen(url) + 1;
            client->cacheNode->url.data = (char *) malloc(sizeof(char) * (strlen(url) + 1));
            memcpy(client->cacheNode->url.data, url, strlen(url) + 1);

            client->cacheNode->state = WRITE_TO_SERVER;
            client->cacheNode->numberOfUsers = 1;
            client->cacheNode->numberOfRdyBytes = 0;
        }
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

    /*printf("CHECK THEM\n");
    for (int i = client->client.bytesInBuffer; i < client->client.bytesInBuffer + bytesRead; ++i){
        printf("%c", client->client.buffer[i]);
    }
    printf("ITS ALL\n\n");*/

    client->client.readedFromServerBytes += bytesRead;
    client->client.bytesInBuffer += bytesRead;
    ssize_t flag;
    if (client->cacheNode) {
        switch (client->cacheNode->state) {
            case READY:
                printf("CASE READY\n");
                close(client->client.serverSocket);
                client->client.connectionState = WRITE_TO_CLIENT;
                client->client.answer.size = client->cacheNode->answer.size;
                client->client.bytesInBuffer = client->client.answer.size;
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
                        client->cacheNode->answer.data = (char *) malloc(flag * sizeof(char));
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
                    return;
                }
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

                        return;
                    }
                }
                break;
            default:
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


void handleWriteToServer(Clients_struct *client) {
    //in this function bytesInBuffer isn't number of bytes in buffer
    //it is a number of bytes that we need to send
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
        } else{
            client->client.bytesInBuffer = 0;
            client->client.connectionState = READ_FROM_SERVER;
        }
        printf("Request are sent \n");
    }
}


void handleWriteToClient(Clients_struct **fullList, Clients_struct *client, int *maxFdP, int our_fd) {
    //in this function bytesInBuffer isn't number of bytes in buffer
    //it is a number of bytes that we need to send
    int bytesWritten = 0;
    int bytesToWrite = PORTION_SIZE;

    char *source;
    int shift;

    if (client->cacheNode) {
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
                return;
        }
        bytesToWrite = (bytesToWrite > PORTION_SIZE) ? PORTION_SIZE : bytesToWrite;
//        printf("%.*s", bytesToWrite,source + shift);
        int bytesWritten = write(client->client.clientSocket, source + shift, bytesToWrite);
        if (bytesWritten < 0) {
            //HANDLE MISTAKE
        }
        client->client.writtenToClientBytes += bytesWritten;

        switch (client->cacheNode->state) {
            case READING_HEAD:
                return;
            default:
                if (client->client.writtenToClientBytes == client->cacheNode->answer.size) {
                    printf("We sent our message to the client\n");
                    printf("Session is over\n");

                    client->cacheNode->numberOfUsers -= 1;
                    int clSocket = client->client.clientSocket;
                    int svSocket = client->client.serverSocket;

                    deleteFromList(fullList, clSocket);
                    updateMaxFd(maxFdP, *fullList, clSocket, svSocket, our_fd);
                    close(clSocket);
                    printf("\n");
                }
        }
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
            deleteFromList(fullList, clSocket);
            updateMaxFd(maxFdP, *fullList, clSocket, svSocket, our_fd);
            close(clSocket);
            return;
        }

        if (client->client.connectionState == ONLY_WRITE_TO_CLIENT &&
            client->client.writtenToClientBytes % BUF_SIZE == 0) {
            client->client.connectionState = READ_FROM_SERVER;
            client->client.bytesInBuffer = 0;
        }
    }
}

int main(int argc, char **argv) {

    int our_fd = 0;


    Clients_struct *client = NULL;

    struct sockaddr_in our_addr = {0};


    our_addr.sin_family = AF_INET;
    our_addr.sin_port = htons(LISTEN_PORT);
    our_addr.sin_addr.s_addr = INADDR_ANY;


    our_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (-1 == our_fd) {
        perror("Can't create socket\n");
        return 1;
    }

    printf("Binding socket ...\n");
    if (0 != bind(our_fd,
                  (struct sockaddr *) &our_addr,
                  sizeof(our_addr))
            ) {
        perror("Can't bind socket to address\n");
        return 1;
    }

    if (0 != listen(our_fd, 128)) {
        perror("Can't listen to interface\n");
        return 1;
    }

    fd_set readSet;
    fd_set writeSet;

    int maxFd = our_fd + 1;
    int client_addr_size = sizeof(struct sockaddr_in);
    Clients_struct *tmp;

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (1) {
        refreshOurSets(client, &readSet, &writeSet, our_fd);
        int ret_value = select(maxFd, &readSet, &writeSet, NULL, NULL);

        if (FD_ISSET(our_fd, &readSet)) {
            printf("BEFORE HANDLE NEW CONNECTION\n");
            handleNewConnection(&client, &maxFd, our_fd);
            printf("AFTER HANDLE NEW CONNECTION\n");
        }
        tmp = client;

        while (tmp) {
            Clients_struct *next = tmp->next;
            switch (tmp->client.connectionState) {
                case READ_FROM_CLIENT://time to read from client?
                    if (FD_ISSET(tmp->client.clientSocket, &readSet)) {
                        handleReadFromClient(&client, tmp, &maxFd, our_fd);
                    }
                    break;
                case READ_FROM_SERVER://time to read from server?
                    if (FD_ISSET(tmp->client.serverSocket, &readSet)) {
                        handleReadFromServer(tmp);
                        if (FD_ISSET(tmp->client.clientSocket, &writeSet)) {
                            handleWriteToClient(&client, tmp, &maxFd, our_fd);
                        }
                    }
                    break;
                case WRITE_TO_SERVER://time to write to server?
                    if (FD_ISSET(tmp->client.serverSocket, &writeSet)) {
                        handleWriteToServer(tmp);
                    }
                    break;
                case ONLY_WRITE_TO_CLIENT:
                case WRITE_TO_CLIENT://time to write to client?
                    if (FD_ISSET(tmp->client.clientSocket, &writeSet)) {
                        handleWriteToClient(&client, tmp, &maxFd, our_fd);

                    }
                    break;
                case ONLY_READ_FROM_SERVER:
                    if (FD_ISSET(tmp->client.serverSocket, &readSet)) {
                        handleReadFromServer(tmp);

                    }
                default:
                    break;
            }
            tmp = next;
        }
    }
#pragma clang diagnostic pop
    return 0;
}
