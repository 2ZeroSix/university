#pragma once

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <cstdint>
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
#include "picohttpparser.h"
class Proxy {
    const static size_t BUF_SIZE        = 65536;
    const static size_t PACKET_SIZE     = 1024;
    const static size_t MAX_CONNECTIONS = 1024;
    const static uint16_t HTTP_PORT     = 80;
    uint16_t LISTEN_PORT                = 5000;



    struct Connection {
        enum class State {
            NONE,
            READ_FROM_CLIENT,
            WRITE_TO_SERVER,
            READ_FROM_SERVER,
            WRITE_TO_CLIENT,
        } state{State::NONE};
        char *method, *path;
        size_t buflen{};
        size_t prevbuflen{};
        size_t method_len{};
        size_t path_len{};
        size_t num_headers{};
        size_t bytesInBuffer{};
        int minor_version;
        int client{};
        int server{};
        std::vector<char> buffer = std::vector<char>(BUF_SIZE);
        phr_header headers[100];
        void close() {
            ::close(client);
            ::close(server);
            *this = Connection{};
        }
    };


    std::vector<Connection> connections{MAX_CONNECTIONS};
    size_t connectionsCount = 0;
    fd_set readSet;
    fd_set writeSet;
    int our_fd;
    int maxFdP;

    int getFreeFd() {
        for (int i = 0; i < MAX_CONNECTIONS; i++) {
            if (connections[i].state == Connection::State::NONE) {
                return i;
            }
        }
        return -1;
    }


    void refreshOurSets(){
        FD_ZERO(&readSet);
        FD_ZERO(&writeSet);
        FD_SET(our_fd, &readSet);

        for (int i = 0; i < MAX_CONNECTIONS; i++) {
            switch(connections[i].state) {
                case Connection::State::READ_FROM_CLIENT:
                    FD_SET(connections[i].client, &readSet);
                    //printf("PUT CLIENT READ\n");
                    break;
                case Connection::State::READ_FROM_SERVER:
                    FD_SET(connections[i].server, &readSet);
                    //printf("PUT SERVER READ\n");
                    break;
                case Connection::State::WRITE_TO_SERVER:
                    FD_SET(connections[i].server, &writeSet);
                    //printf("PUT SERVER WRITE\n");
                    break;
                case Connection::State::WRITE_TO_CLIENT:
                    FD_SET(connections[i].client, &writeSet);
                    //printf("PUT CLIENT WRITE\n");
                    break;
                default:
                    break;
            }
        }
    }


    void handleNewConnection(){

        printf("Accept connection ...\n");

        int index = getFreeFd();
        if (-1 == index){
            return;
        }
        connections[index] = (Connection){};
        connections[index].state = Connection::State::READ_FROM_CLIENT;
        connections[index].client = accept(our_fd, nullptr, nullptr);
        if (connections[index].client > maxFdP - 1) {
            maxFdP = connections[index].client + 1;
        }
        ++connectionsCount;
    }

    void updateMaxFd(int sessionIndex){
        if ((connections[sessionIndex].server == (maxFdP - 1)) ||
            (connections[sessionIndex].client == (maxFdP - 1)) ) {

            maxFdP = our_fd + 1;
            for (int j = 0; j < MAX_CONNECTIONS; j++) {
                if (connections[j].state != Connection::State::NONE) {
                    if (maxFdP - 1 < connections[j].server) {
                        maxFdP = connections[j].server + 1;
                    }
                    if (maxFdP - 1 < connections[j].client ) {
                        maxFdP = connections[j].client + 1;
                    }
                }
            }
        }
    }

    std::string getPath(std::vector<char> request){
        int start = -1;
        int end   = -1;
        int count = 0;
        if (request[4] != 104){
//            cout << (int)request[4] << endl;
            return std::string();
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
            return std::string();
        }
        for (int i = start; i < request.size(); ++i){
            if (request[i] == '/'){
                end = i;
                break;
            }
        }
        if (end == -1){
            return std::string();
        }
        return std::string(request.data() + start, static_cast<unsigned long>(end - start));
    }


    void handleReadFromClient(Connection& connection){

        ssize_t bytesRead = read( connection.client,
                                  connection.buffer.data() + connection.bytesInBuffer,
                                  PACKET_SIZE);
        std::cout << "Bytes Read : " << bytesRead << std::endl;
        connection.bytesInBuffer += bytesRead;
        if (bytesRead < 0) {
            connection.close();
        }
//        if ((   connections[sessionIndex].bytesInBuffer >= 4 &&
//                connections[sessionIndex].buffer[connections[sessionIndex].bytesInBuffer - 1] == '\r' &&
//                connections[sessionIndex].buffer[connections[sessionIndex].bytesInBuffer - 2] == '\n' &&
//                connections[sessionIndex].buffer[connections[sessionIndex].bytesInBuffer - 3] == '\r' &&
//                connections[sessionIndex].buffer[connections[sessionIndex].bytesInBuffer - 4] == '\n')){
//            return; // TODO
//        }

        connection.state = Connection::State::WRITE_TO_SERVER;

        std::cout << "Request received: " << std::endl;
        for (int j = 0; j < connection.bytesInBuffer; ++j) {
            printf("%c", connection.buffer[j]);
        }

        if ( !isItGetRequest(connection.buffer) ) {
            printf("Do not support this type of message\n");
            printf("Session is over\n");

            connection.close();
            return;
        }

        int index = findAnswerInCache(connection.buffer);

        if (-1 != index) {//we have an answer in the cache
            connection.state = Connection::State::WRITE_TO_CLIENT;
            connection.buffer = cache[index].answer;
//		memcpy(connections[sessionIndex].answer.data, cache[index].answer.data, cache[index].answer.size);
            //connections[sessionIndex].answer.data = cache[index].answer.data;
            connection.bytesInBuffer = connection.buffer.size();
            //bytesInBuffer is a special
            //check handleWriteToClient() for details
        }
        else {
            struct sockaddr_in server_addr = {0};
            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(HTTP_PORT);
            std::string path = getPath(connection.buffer);
            std::cout << path << std::endl;
            struct hostent * host_info = gethostbyname(path.data());
            if(host_info == nullptr){
                printf(" gethostbyname() failed\n");
                return; // TODO exception
            }

            std::copy(host_info->h_addr, host_info->h_addr + host_info->h_length, (char*)&server_addr.sin_addr);
            //server_addr.sin_addr.s_addr = inet_addr(argv[1]);

            connection.server = socket(AF_INET, SOCK_STREAM, 0);
            if ( maxFdP - 1 < connection.server ) {
                maxFdP = connection.server + 1;
            }

            if (0 != connect( connection.server,
                              (struct sockaddr *) &server_addr,
                              sizeof(server_addr))
                    ) {
                perror("Can't connect to server address\n");
                return; // TODO exception
            }
            connection.bytesInBuffer = connection.buffer.size();
        }

    }

    void handleReadFromServer(Connection& client){
        printf("Receiving answer : \n");

        ssize_t bytesRead = read(client.server,
                                 client.buffer.data() + client.bytesInBuffer,
                                 PACKET_SIZE );
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






    void handleWriteToServer(Connection& client){
        //in this function bytesInBuffer isn't number of bytes in buffer
        //it is a number of bytes that we need to send
        ssize_t bytesWritten = 0;
        size_t bytesToWrite = PACKET_SIZE;

        if (client.bytesInBuffer <= PACKET_SIZE ) {
            bytesToWrite = client.bytesInBuffer;
        }

        bytesWritten = write(client.server,
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


    void handleWriteToClient(std::vector<Connection>& client, int sessionIndex, std::vector<bool>& sessionIsUsed, int &maxFdP, int our_fd){
        //in this function bytesInBuffer isn't number of bytes in buffer
        //it is a number of bytes that we need to send
        ssize_t bytesWritten = 0;
        size_t bytesToWrite = PACKET_SIZE;

        if ( client[sessionIndex].bytesInBuffer <= PACKET_SIZE ) {
            bytesToWrite = client[sessionIndex].bytesInBuffer;
        }

        bytesWritten = write(client[sessionIndex].client,
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

            close(client[sessionIndex].client);
            close(client[sessionIndex].server);
            printf("\n");
        }
    }
public:
    void* run(void* arg) {

        struct sockaddr_in our_addr = {0};

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


        while (true) {
            refreshOurSets(client, sessionIsUsed, readSet, writeSet, our_fd);
            int ret_value = select(maxFd, &readSet, &writeSet, nullptr, nullptr);
            if (ret_value == -1) return reinterpret_cast<void *>(1);
            if (FD_ISSET(our_fd, &readSet)) {
                handleNewConnection();

            }

            for (int i = 0; i < MAX_CONNECTIONS; i++) {
                if (!sessionIsUsed[i]){
                    continue;
                }
                switch(client[i].connectionState){
                    case READ_FROM_CLIENT:
                        if (FD_ISSET(client[i].client, &readSet) ) {
                            handleReadFromClient(client, sessionIsUsed, i,  maxFd,
                                                 our_fd);
                        }
                        break;
                    case READ_FROM_SERVER:
                        if (FD_ISSET(client[i].server, &readSet)) {
                            handleReadFromServer(client[i]);
                        }
                        break;
                    case WRITE_TO_SERVER:
                        if (FD_ISSET(client[i].server, &writeSet)) {
                            handleWriteToServer(client[i]);
                        }
                        break;
                    case WRITE_TO_CLIENT:
                        if (FD_ISSET(client[i].client, &writeSet) ) {
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

