#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <string>
#include <vector>
#include <iostream>

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
using namespace std;


class Proxy {
    enum {
        READ_FROM_CLIENT,
        WRITE_TO_SERVER,
        READ_FROM_SERVER,
        WRITE_TO_CLIENT,
    };
    struct CacheData{
        vector<char> request;
        vector<char> answer;
    };
    const static size_t BUF_SIZE         = 65536;
    struct ConnectionInfo{
        int clientSocket{};
        int serverSocket{};

        int connectionState{};

        size_t bytesInBuffer{};
        vector<char> request;
        vector<char> answer;
        vector<char> buffer = vector<char>(BUF_SIZE);
    };
    size_t PORTION_SIZE     = 1024;
    size_t CACHE_SIZE       = 1024;
    size_t MAX_CONNECTIONS  = 10;
    uint16_t HTTP_PORT        = 80;
    uint16_t LISTEN_PORT      = 5000;
    vector<CacheData> cache{CACHE_SIZE};
    int getFreeFd(const vector<bool>& fdIsUsed) {
        for (int i = 0; i < MAX_CONNECTIONS; i++) {
            if (!fdIsUsed[i]) {
                return i;
            }
        }
        return -1;
    }


    int isItGetRequest(const vector<char>& request ) {
        return ((request.size() >= 3) &&
                ('G' == request[0]) &&
                ('E' == request[1]) &&
                ('T' == request[2]));
    }


    void cachePush(const vector<char>& request, const vector<char>& answer) {
        static int cashState = 0;

        CacheData result;
        result.request = request;
        result.answer  = answer;

        cache[cashState] = result;
        cashState = (cashState + 1 == CACHE_SIZE) ? 0 :(cashState + 1);
    }


    int findAnswerInCache(const vector<char>& request) {
        for (int i = 0; i < CACHE_SIZE; i++) {
            if (cache[i].request == request) {
                printf("Answer is from the cache\n");
                return i;
            }
        }
        printf("Answer is not found in the cache\n");
        return -1;
    }


    void refreshOurSets(vector<ConnectionInfo>& client, const vector<bool>& sessionIsUsed, fd_set& readSet, fd_set& writeSet, int our_fd){
        FD_ZERO(&readSet);
        FD_ZERO(&writeSet);
        FD_SET(our_fd, &readSet);

        for (int i = 0; i < MAX_CONNECTIONS; i++) {
            if (sessionIsUsed[i]) {
                switch(client[i].connectionState){
                    case READ_FROM_CLIENT:
                        FD_SET(client[i].clientSocket, &readSet);
                        //printf("PUT CLIENT READ\n");
                        break;
                    case READ_FROM_SERVER:
                        FD_SET(client[i].serverSocket, &readSet);
                        //printf("PUT SERVER READ\n");
                        break;
                    case WRITE_TO_SERVER:
                        FD_SET(client[i].serverSocket, &writeSet);
                        //printf("PUT SERVER WRITE\n");
                        break;
                    case WRITE_TO_CLIENT:
                        FD_SET(client[i].clientSocket, &writeSet);
                        //printf("PUT CLIENT WRITE\n");
                        break;
                    default:
                        break;
                }
            }
        }
    }


    void handleNewConnection(vector<bool>& sessionIsUsed, vector<ConnectionInfo>& client, int& maxFdP,
                             vector<sockaddr_in>& cl_addr, int& addr_size, int our_fd){

        printf("Accept connection ...\n");

        int index = getFreeFd(sessionIsUsed);
        if (-1 == index){
            return;
        }
        sessionIsUsed[index] = true;
        client[index] = (ConnectionInfo){};
        client[index].connectionState = READ_FROM_CLIENT;
        client[index].clientSocket = accept(
                our_fd,
                (struct sockaddr *) &cl_addr[index],
                (socklen_t *) &addr_size);
        if (client[index].clientSocket > maxFdP - 1) {
            maxFdP = client[index].clientSocket + 1;
        }
    }

    void updateMaxFd(int& maxFdP, vector<ConnectionInfo>& client, const vector<bool> &sessionIsUsed, int sessionIndex, int our_fd){
        if ((client[sessionIndex].serverSocket == (maxFdP - 1)) ||
            (client[sessionIndex].clientSocket == (maxFdP - 1)) ) {

            maxFdP = our_fd + 1;
            for (int j = 0; j < MAX_CONNECTIONS; j++) {
                if (sessionIsUsed[j] ) {
                    if (maxFdP - 1 < client[j].serverSocket) {
                        maxFdP = client[j].serverSocket + 1;
                    }
                    if (maxFdP - 1 < client[j].clientSocket ) {
                        maxFdP = client[j].clientSocket + 1;
                    }
                }
            }
        }
    }

    string getPath(vector<char> request){
        int start = -1;
        int end   = -1;
        int count = 0;
        if (request[4] != 104){
//            cout << (int)request[4] << endl;
            return string();
        }
        start = 5;
        for (int i = start; i < request.size(); ++i){//find "//""
            if (request[i] == '/'){
                if (++count == 2){
                    start = i + 1;
                    break;
                }
            }
        }
        if (count != 2){
            return string();
        }
        for (int i = start; i < request.size(); ++i){
            if (request[i] == '/'){
                end = i;
                break;
            }
        }
        if (end == -1){
            return string();
        }
        return string(request.data() + start, static_cast<unsigned long>(end - start));
    }


    void handleReadFromClient(vector<ConnectionInfo>& client, vector<bool>& sessionIsUsed,int sessionIndex,
                              int& maxFdP, int our_fd){

        ssize_t bytesRead = read( client[sessionIndex].clientSocket,
                                  client[sessionIndex].buffer.data() + client[sessionIndex].bytesInBuffer,
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
        client[sessionIndex].request = vector<char>(client[sessionIndex].buffer.begin(),
                                              client[sessionIndex].buffer.begin()
                                              + client[sessionIndex].bytesInBuffer);

        cout << "Request received: " << endl;
        for (int j = 0; j < client[sessionIndex].bytesInBuffer; ++j) {
            printf("%c", client[sessionIndex].buffer[j]);
        }

        if ( !isItGetRequest(client[sessionIndex].request) ) {
            printf("Do not support this type of message\n");
            printf("Session is over\n");

            sessionIsUsed[sessionIndex] = false;
            updateMaxFd(maxFdP, client, sessionIsUsed, sessionIndex, our_fd);
            close(client[sessionIndex].clientSocket);
            return;
        }

        int index = findAnswerInCache(client[sessionIndex].request);

        if (-1 != index) {//we have an answer in the cache
            client[sessionIndex].connectionState = WRITE_TO_CLIENT;
            client[sessionIndex].answer = cache[index].answer;
//		memcpy(client[sessionIndex].answer.data, cache[index].answer.data, cache[index].answer.size);
            //client[sessionIndex].answer.data = cache[index].answer.data;
            client[sessionIndex].bytesInBuffer = client[sessionIndex].answer.size();
            //bytesInBuffer is a special
            //check handleWriteToClient() for details
        }
        else {
            struct sockaddr_in server_addr = {0};
            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(HTTP_PORT);
            string path = getPath(client[sessionIndex].request);
            cout << path << endl;
            struct hostent * host_info = gethostbyname(path.data());
            if(host_info == nullptr){
                printf(" gethostbyname() failed\n");
                return; // TODO exception
            }

            copy(host_info->h_addr, host_info->h_addr + host_info->h_length, (char*)&server_addr.sin_addr);
            //server_addr.sin_addr.s_addr = inet_addr(argv[1]);

            client[sessionIndex].serverSocket = socket(AF_INET, SOCK_STREAM, 0);
            if ( maxFdP - 1 < client[sessionIndex].serverSocket ) {
                maxFdP = client[sessionIndex].serverSocket + 1;
            }

            if (0 != connect( client[sessionIndex].serverSocket,
                              (struct sockaddr *) &server_addr,
                              sizeof(server_addr))
                    ) {
                perror("Can't connect to server address\n");
                return; // TODO exception
            }
            client[sessionIndex].bytesInBuffer = client[sessionIndex].request.size();
        }

    }

    void handleReadFromServer(ConnectionInfo& client){
        printf("Receiving answer : \n");

        ssize_t bytesRead = read(client.serverSocket,
                                 client.buffer.data() + client.bytesInBuffer,
                                 PORTION_SIZE );
        client.bytesInBuffer += bytesRead;

        if (0 == bytesRead) {
            client.connectionState = WRITE_TO_CLIENT;
            client.answer = vector<char>(client.buffer.begin(), client.buffer.begin() + client.bytesInBuffer);

            printf("We recieved an answer : \n");
            for (char j : client.answer) {
                printf("%c", j);
            }
            client.bytesInBuffer = client.answer.size();
            cachePush(client.request, client.answer);
        }
    }






    void handleWriteToServer(ConnectionInfo& client){
        //in this function bytesInBuffer isn't number of bytes in buffer
        //it is a number of bytes that we need to send
        ssize_t bytesWritten = 0;
        size_t bytesToWrite = PORTION_SIZE;

        if (client.bytesInBuffer <= PORTION_SIZE ) {
            bytesToWrite = client.bytesInBuffer;
        }

        bytesWritten = write(client.serverSocket,
                             client.request.data() +
                             (client.request.size() - client.bytesInBuffer),
                             bytesToWrite);
        client.bytesInBuffer -= bytesWritten;
        if (0 == bytesWritten ) {
            client.bytesInBuffer = 0;
        }

        if (client.bytesInBuffer <= 0 ) {
            client.connectionState = READ_FROM_SERVER;
            client.bytesInBuffer = 0;
            printf("Request are sent \n");
            //sleep(2);
        }
    }


    void handleWriteToClient(vector<ConnectionInfo>& client, int sessionIndex, vector<bool>& sessionIsUsed, int &maxFdP, int our_fd){
        //in this function bytesInBuffer isn't number of bytes in buffer
        //it is a number of bytes that we need to send
        ssize_t bytesWritten = 0;
        size_t bytesToWrite = PORTION_SIZE;

        if ( client[sessionIndex].bytesInBuffer <= PORTION_SIZE ) {
            bytesToWrite = client[sessionIndex].bytesInBuffer;
        }

        bytesWritten = write(client[sessionIndex].clientSocket,
                             client[sessionIndex].answer.data() +
                             (client[sessionIndex].answer.size() - client[sessionIndex].bytesInBuffer),
                             bytesToWrite);

        client[sessionIndex].bytesInBuffer -= bytesWritten;
        if ( 0 == bytesWritten )  {
            client[sessionIndex].bytesInBuffer = 0;
        }

        if (client[sessionIndex].bytesInBuffer <= 0 ) {
            printf("We sent our message to the client\n");
            printf("Session is over\n");
            sessionIsUsed[sessionIndex] = false;
            client[sessionIndex].bytesInBuffer = 0;
            updateMaxFd(maxFdP, client, sessionIsUsed, sessionIndex, our_fd);

            close(client[sessionIndex].clientSocket);
            close(client[sessionIndex].serverSocket);
            printf("\n");
        }
    }
public:
    void* run(void* arg) {
        int our_fd = 0;
        vector<ConnectionInfo> client{MAX_CONNECTIONS};
        vector<bool> sessionIsUsed = vector<bool>(MAX_CONNECTIONS);

        struct sockaddr_in our_addr = {0};
        vector<struct sockaddr_in> client_addr{MAX_CONNECTIONS};


        our_addr.sin_family = AF_INET;
        our_addr.sin_port = htons(LISTEN_PORT);

        our_addr.sin_addr.s_addr = INADDR_ANY;


        our_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (-1 == our_fd) {
            perror("Can't create socket\n");
            return reinterpret_cast<void *>(1);
        }
        int flag = 1;
        if (-1 == setsockopt(our_fd, 0, SO_REUSEADDR, &flag, sizeof(int))) {
            perror("Can't set option\n");
        }
        printf("Binding socket ...\n");
        if (0 != bind( our_fd,
                       (struct sockaddr *) &our_addr,
                       sizeof(our_addr))
                ) {
            perror("Can't bind socket to address\n");
            return reinterpret_cast<void *>(1);
        }

        if (0 != listen(our_fd, MAX_CONNECTIONS)) {
            perror("Can't listen to interface\n");
            return reinterpret_cast<void *>(1);
        }

        fd_set readSet;
        fd_set writeSet;

        int maxFd = our_fd + 1;
        int client_addr_size = sizeof(struct sockaddr_in);


        while (true) {
            refreshOurSets(client, sessionIsUsed, readSet, writeSet, our_fd);
            int ret_value = select(maxFd, &readSet, &writeSet, nullptr, nullptr);
            if (ret_value == -1) return reinterpret_cast<void *>(1);
            if (FD_ISSET(our_fd, &readSet)) {
                handleNewConnection(sessionIsUsed, client, maxFd,
                                    client_addr, client_addr_size, our_fd);

            }

            for (int i = 0; i < MAX_CONNECTIONS; i++) {
                if (!sessionIsUsed[i]){
                    continue;
                }
                switch(client[i].connectionState){
                    case READ_FROM_CLIENT:
                        if (FD_ISSET(client[i].clientSocket, &readSet) ) {
                            handleReadFromClient(client, sessionIsUsed, i,  maxFd,
                                                 our_fd);
                        }
                        break;
                    case READ_FROM_SERVER:
                        if (FD_ISSET(client[i].serverSocket, &readSet)) {
                            handleReadFromServer(client[i]);
                        }
                        break;
                    case WRITE_TO_SERVER:
                        if (FD_ISSET(client[i].serverSocket, &writeSet)) {
                            handleWriteToServer(client[i]);
                        }
                        break;
                    case WRITE_TO_CLIENT:
                        if (FD_ISSET(client[i].clientSocket, &writeSet) ) {
                            handleWriteToClient(client, i, sessionIsUsed, maxFd, our_fd);
                        }
                        break;
                    default:
                        break;
                }
            }
        }
    }
};









int main ( int argc, char ** argv ) {
    Proxy proxy;
    return static_cast<int>((ptrdiff_t)proxy.run(nullptr));

}

#pragma clang diagnostic pop