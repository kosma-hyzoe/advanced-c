#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define IPV4_ADDR "127.0.0.1"
/*
 * this version is somewhat primitive - I will try some loops and the
 * "multi-client-no-multi-threading" version soon.
 */
int main(int argc, char const *argv[])
{
    int opt = 1;
    struct sockaddr_in address;
    int addrlen = sizeof(address);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket failed");
        return -1;
    }
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind");
        close(server_fd);
        return -1;
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        close(server_fd);
        return -1;
    }

    /* recieving codemsg from cli1 */
    uint32_t codemsg;
    int cli1sckt =
        accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
    if (cli1sckt < 0) {
        perror("accept");
        return -1;
    }

    int valread = read(cli1sckt, &codemsg, sizeof(uint32_t));
    if (valread <= 0) {
        perror("read");
        close(cli1sckt);
        return -1;
    } else {
        printf("SERVER: Code message received from client1: %d\n", codemsg);
    }
    close(cli1sckt);

    /* decrementing codemsg and sending it to cli2 */
    codemsg--;
    int cli2sckt =
        accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
    if (cli2sckt < 0) {
        perror("accept");
        close(cli2sckt);
        return -1;
    }
    printf("SERVER: Sending code message '%d' to client2...\n", codemsg);
    int valwrite = write(cli1sckt, &codemsg, sizeof(uint32_t));
    if (valwrite < 0) {
        perror("send");
        close(cli2sckt);
        return -1;
    }
    close(cli2sckt);

    shutdown(server_fd, SHUT_RDWR);
}
