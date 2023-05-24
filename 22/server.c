// Server side C/C++ program to demonstrate Socket
// programming
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define IPV4_ADDR "127.0.0.1"
/*
 * this version is somewhat primitive - I will try the
 * "multi-client-no-multi-threading version soon.
 */
int main(int argc, char const *argv[])
{
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    /* SO_REUSEADDR | SO_REUSEPORT ? */
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    /* recieving ans from cli1 */
    uint32_t ans;
    int cli1sckt =
        accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
    if (cli1sckt < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    int valread = read(cli1sckt, &ans, sizeof(uint32_t));
    if (valread <= 0) {
            perror("read");
            close(cli1sckt);
            exit(EXIT_FAILURE);
    } else {
        printf("Data from client1: %d\n", ans);
    }
    close(cli1sckt);

    /* decrementing ans and sending it to cli2 */
    ans--;
    int cli2sckt =
        accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
    if (cli2sckt < 0) {
        perror("accept");
        close(cli2sckt);
        exit(EXIT_FAILURE);
    }

    int sent = write(cli1sckt, &ans, sizeof(uint32_t));
    if (sent < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    close(cli1sckt);

    shutdown(server_fd, SHUT_RDWR);
}
