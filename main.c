#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include "main.h"

#define LOCALHOST "127.0.0.1"
#define LOCALPORT 8080

int main(int argc, char **argv) {
    int main_socket, success;
    struct sockaddr_in addr;
    main_socket = socket(AF_INET, SOCK_STREAM, 0);
    assert(main_socket > -1, SOCKERRMSG, E_SOCK_NO_INIT);

    addr.sin_family = AF_INET;
    addr.sin_port   = htons(LOCALPORT);
    inet_aton(LOCALHOST, &addr.sin_addr.s_addr);

    assert(!bind(main_socket, (struct sockaddr*)&addr, sizeof(addr)), SOCKERRMSG, E_SOCK_NO_BIND);
    assert(!listen(main_socket, 0xF), SOCKERRMSG, E_SOCK_NO_LISTEN);
    assert(!accept(main_socket, NULL, NULL), SOCKERRMSG, E_SOCK_NO_ACCEPT);

    close(main_socket);
    return 0;
}


