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

int main(int argc, char const *argv[])
{
    int server_fd, sckt, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    char *hello = "Hello from server";

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if ((server_fd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    } if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    sckt = accept(server_fd, (struct sockaddr *)&address,(socklen_t *)&addrlen);
    if ((sckt < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    valread = read(sckt, buffer, 1024);
    printf("%s\n", buffer);
    send(sckt, hello, strlen(hello), 0);
    printf("Hello message sent\n");

    // closing the connected socket
    close(sckt);
    // closing the listening socket
    shutdown(server_fd, SHUT_RDWR);
    return 0;
}
