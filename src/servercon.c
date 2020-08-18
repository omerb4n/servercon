#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include "network.h"
#include "errors.h"

int servercon_loop();

int servercon(unsigned int lport) {
    setvbuf(stdout, NULL, _IONBF, 0);
    printf("Listening on port %d\n", lport);
    int sockfd = listen_inet_socket(lport);
    return servercon_loop(sockfd);
}
int servercon_loop(int sockfd) {
    while(1) {
        struct sockaddr_storage client_addr;
        unsigned int address_size = sizeof(client_addr);
        printf("Waiting for connection");
        int connect_d = accept(sockfd, (struct sockaddr*)&client_addr, &address_size);
        if (connect_d == -1)
            handle_error(SOCKET_ERROR, "Can't open secondary socket");
        printf("Connection Accepted");
        
    }
    return 0;
}