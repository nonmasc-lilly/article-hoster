#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define LOCALHOST "127.0.0.1"
#define LOCALPORT 8080

int writestr(int fd, const char *str);

int main(int argc, char **argv) {
    int main_socket;
    struct sockaddr_in addr;
    main_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(main_socket < 0)
        writestr(1, "!! main_socket could not init\n");
    addr.sin_family = AF_INET;
    addr.sin_port   = htons(LOCALPORT);
    inet_aton(LOCALHOST, &addr.sin_addr.s_addr);
    bind(main_socket, (struct sockaddr*)&addr, sizeof(addr));
    listen(main_socket, 16);
    accept(main_socket, NULL, NULL);
    close(main_socket);
    return 0;
}

int writestr(int fd, const char *str) {
    int count;
    const char *strp;
    for(strp = str; *strp; strp++);
    count = (int)(strp-str);
    return write(fd, str, count);
}

