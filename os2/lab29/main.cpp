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
        WRITE_PART_TO_CLIENT
    };
    struct CacheData{
        vector<char> request;
        vector<char> answer;
    };
    const static size_t BUF_SIZE        = 65536;
    struct ConnectionInfo{
        int clientSocket{};
        int serverSocket{};

        int connectionState{};

        size_t bytesInBuffer{};
        vector<char> request;
        vector<char> answer;
        vector<char> buffer = vector<char>(BUF_SIZE);
    };
    size_t PACKET_SIZE                  = 8192;
    size_t CACHE_SIZE                   = 10;
    size_t CLIENTS_MAX                  = 10;
    static const uint16_t HTTP_PORT     = 80;
    uint16_t LISTEN_PORT                = 5000;
    vector<CacheData> cache{CACHE_SIZE};
    int getFreeFd(const vector<bool>& fdIsUsed) {
        for (int i = 0; i < CLIENTS_MAX; i++) {
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
                cout << "Answer is from the cache" << endl;
                return i;
            }
        }
        cout << "Answer is not found in the cache" << endl;
        return -1;
    }


    void refreshOurSets(vector<ConnectionInfo>& client, const vector<bool>& sessionIsUsed, fd_set& readSet, fd_set& writeSet, int our_fd){
        FD_ZERO(&readSet);
        FD_ZERO(&writeSet);
        FD_SET(our_fd, &readSet);

        for (int i = 0; i < CLIENTS_MAX; i++) {
            if (sessionIsUsed[i]) {
                switch(client[i].connectionState){
                    case READ_FROM_CLIENT:
                        FD_SET(client[i].clientSocket, &readSet);
                        break;
                    case READ_FROM_SERVER:
                        FD_SET(client[i].serverSocket, &readSet);
                        break;
                    case WRITE_TO_SERVER:
                        FD_SET(client[i].serverSocket, &writeSet);
                        break;
                    case WRITE_TO_CLIENT:
                    case WRITE_PART_TO_CLIENT:
                        FD_SET(client[i].clientSocket, &writeSet);
                        break;
                    default:
                        break;
                }
            }
        }
    }


    void handleNewConnection(vector<bool>& sessionIsUsed, vector<ConnectionInfo>& client, int& maxFdP,
                             vector<sockaddr_in>& cl_addr, int& addr_size, int our_fd){

        cout << "Accept connection ..." << endl;

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
            for (int j = 0; j < CLIENTS_MAX; j++) {
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
                                  PACKET_SIZE);
        cout << "Bytes Read : " << bytesRead << endl;
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
            cout << client[sessionIndex].buffer[j];
        }

        if ( !isItGetRequest(client[sessionIndex].request) ) {
            cout << "Do not support this type of message" << endl;
            cout << "Session is over" << endl;

            sessionIsUsed[sessionIndex] = false;
            updateMaxFd(maxFdP, client, sessionIsUsed, sessionIndex, our_fd);
            close(client[sessionIndex].clientSocket);
            return;
        }

        int index = findAnswerInCache(client[sessionIndex].request);

        if (-1 != index) {//we have an answer in the cache
            client[sessionIndex].connectionState = WRITE_TO_CLIENT;
            client[sessionIndex].answer = cache[index].answer;
            client[sessionIndex].bytesInBuffer = client[sessionIndex].answer.size();
        }
        else {
            struct sockaddr_in server_addr = {0};
            server_addr.sin_family = AF_INET;
            server_addr.sin_port = htons(HTTP_PORT);
            string path = getPath(client[sessionIndex].request);
            cout << path << endl;
            struct hostent * host_info = gethostbyname(path.data());
            if(host_info == nullptr){
                cout << " gethostbyname() failed" << endl;
                return;
            }

            copy(host_info->h_addr, host_info->h_addr + host_info->h_length, (char*)&server_addr.sin_addr);

            client[sessionIndex].serverSocket = socket(AF_INET, SOCK_STREAM, 0);
            if ( maxFdP - 1 < client[sessionIndex].serverSocket ) {
                maxFdP = client[sessionIndex].serverSocket + 1;
            }

            if (0 != connect( client[sessionIndex].serverSocket,
                              (struct sockaddr *) &server_addr,
                              sizeof(server_addr))) {
                cout << "Can't connect to server address" << endl;
                return;
            }
            client[sessionIndex].bytesInBuffer = client[sessionIndex].request.size();
        }

    }

    void handleReadFromServer(ConnectionInfo& client){
        cout << "Receiving answer : " << endl;

        ssize_t bytesRead = read(client.serverSocket,
                                 client.buffer.data() + client.bytesInBuffer,
                                 PACKET_SIZE );
        client.bytesInBuffer += bytesRead;
        if (0 == bytesRead) {
            client.connectionState = WRITE_PART_TO_CLIENT;
            client.answer = vector<char>(client.buffer.begin(), client.buffer.begin() + client.bytesInBuffer);

            cout << "Answer received : " << endl;
            for (char j : client.answer) {
                cout << j;
            }
            client.serverSocket = -1;
            client.bytesInBuffer = client.answer.size();
            cachePush(client.request, client.answer);
        } else if (client.bytesInBuffer + PACKET_SIZE > BUF_SIZE) {

        }
    }






    void handleWriteToServer(ConnectionInfo& client){
        ssize_t bytesWritten = 0;
        size_t bytesToWrite = PACKET_SIZE;

        if (client.bytesInBuffer <= PACKET_SIZE ) {
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
            cout << "Request are sent" << endl;
        }
    }


    void handleWriteToClient(vector<ConnectionInfo>& client, int sessionIndex, vector<bool>& sessionIsUsed, int &maxFdP, int our_fd){
        ssize_t bytesWritten = 0;
        size_t bytesToWrite = PACKET_SIZE;

        if ( client[sessionIndex].bytesInBuffer <= PACKET_SIZE ) {
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
            if (client[sessionIndex].serverSocket != -1) {
                client[sessionIndex].bytesInBuffer = 0;
                client[sessionIndex].connectionState = READ_FROM_SERVER;
            }
            cout << "We sent our message to the client" << endl;
            cout << "Session is over" << endl;
            sessionIsUsed[sessionIndex] = false;
            client[sessionIndex].bytesInBuffer = 0;
            updateMaxFd(maxFdP, client, sessionIsUsed, sessionIndex, our_fd);

            close(client[sessionIndex].clientSocket);
            close(client[sessionIndex].serverSocket);
            cout << endl;
        }
    }
public:
    void* run(void* arg) {
        int our_fd = 0;
        vector<ConnectionInfo> client{CLIENTS_MAX};
        vector<bool> sessionIsUsed = vector<bool>(CLIENTS_MAX);

        struct sockaddr_in our_addr = {0};
        vector<struct sockaddr_in> client_addr{CLIENTS_MAX};


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
        cout << "Binding socket ..." << endl;
        if (0 != bind( our_fd,
                       (struct sockaddr *) &our_addr,
                       sizeof(our_addr))
                ) {
            perror("Can't bind socket to address\n");
            return reinterpret_cast<void *>(1);
        }

        if (0 != listen(our_fd, CLIENTS_MAX)) {
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
            if (FD_ISSET(our_fd, &readSet) && getFreeFd(sessionIsUsed) != -1) {
                handleNewConnection(sessionIsUsed, client, maxFd,
                                    client_addr, client_addr_size, our_fd);

            }

            for (int i = 0; i < CLIENTS_MAX; i++) {
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
                    case WRITE_PART_TO_CLIENT:
                        if (FD_ISSET(client[i].clientSocket, &writeSet)) {
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