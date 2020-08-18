#include <sys/socket.h>
#include <arpa/inet.h>
#include "errors.h"

#define N_BACKLOG 64

int listen_inet_socket(int port) {
    int listener_d = socket(PF_INET, SOCK_STREAM, 0);
    if (listener_d == -1)
        handler_error(SOCKET_ERROR, "Can't open socket");
    struct sockaddr_in name;
    name.sin_family = PF_INET;
    name.sin_port = (in_port_t)htons(port);
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(listener_d, (struct sockaddr *) &name, sizeof(name)) == -1)
        handler_error(SOCKET_ERROR, "Can't bind socket");
    if (listen(listener_d, N_BACKLOG) == -1)
        handler_error(SOCKET_ERROR, "Socket can't listen");
    return listener_d;
}