#include <stdio.h>

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
#include <cassert>
#include "picohttpparser.h"
//#include "Proxy.h"
//#include "Cache.h"

using namespace std;

int main ( int arc, char ** argv ) {
//    Cache cache;
//    Proxy proxy;
//    return static_cast<int>((ptrdiff_t)proxy.run(nullptr));
    int our_fd = 0;

    struct sockaddr_in our_addr = {0};
    struct sockaddr_in client_addr = {0};


    our_addr.sin_family = AF_INET;
    our_addr.sin_port = htons(5000);


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

    if (0 != listen(our_fd, 1)) {
        perror("Can't listen to interface\n");
        return 1;
    }

    int client_addr_size = sizeof(struct sockaddr_in);

    int sock = accept(
            our_fd,
            (struct sockaddr *) &client_addr,
            (socklen_t *) &client_addr_size);

    char buf[4096], *method, *path;
    int pret, minor_version;
    struct phr_header headers[100];
    size_t buflen = 0, prevbuflen = 0, method_len, path_len, num_headers;
    ssize_t rret;

    while (1) {
        /* read the request */
        while ((rret = read(sock, buf + buflen, sizeof(buf) - buflen)) == -1 && errno == EINTR)
            ;
        if (rret <= 0)
            return 1;
        prevbuflen = buflen;
        buflen += rret;
        /* parse the request */
        num_headers = sizeof(headers) / sizeof(headers[0]);
        pret = phr_parse_request(buf, buflen, const_cast<const char **>(&method), &method_len,
                                 const_cast<const char **>(&path), &path_len,
                                 &minor_version, headers, &num_headers, prevbuflen);
        if (pret > 0)
            break; /* successfully parsed the request */
        else if (pret == -1)
            return 2;
        /* request is incomplete, continue the loop */
        assert(pret == -2);
        if (buflen == sizeof(buf))
            return 2;
    }
    printf("%.*s", buflen, buf);
    printf("request is %d bytes long\n", pret);
    printf("method is %.*s\n", (int)method_len, method);
    printf("path is %.*s\n", (int)path_len, path);
    printf("HTTP version is 1.%d\n", minor_version);
    printf("headers:\n");
    for (int i = 0; i != num_headers; ++i) {
        printf("%.*s: %.*s\n", (int)headers[i].name_len, headers[i].name,
               (int)headers[i].value_len, headers[i].value);
    }
    close(our_fd);
}
