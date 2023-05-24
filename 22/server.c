#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
/*
 * this version is somewhat primitive - I will try some loops and the
 * "multi-client-no-multi-threading" version soon.
 */
int main(int argc, char const *argv[])
{

    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) {
        perror("socket");
        return -1;
    }
    /* OPTIONAL: set socket options to prevent "address already in use" */
    int opt = 1;
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)))
        perror("setsockopt");

    struct sockaddr_in address;
    int addrlen = sizeof(address);
    address.sin_family = AF_INET; /* IPV4 */
    address.sin_addr.s_addr = INADDR_ANY; /* any incoming messages */
    address.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind");
        close(server_fd);
        return -1;
    }
    if (listen(server_fd, 1) < 0) {
        perror("listen");
        close(server_fd);
        return -1;
    }

    /* recieving codemsg from cli1 */
    uint32_t codemsg;
    int cli1_fd =
        accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
    if (cli1_fd < 0) {
        perror("accept");
        return -1;
    }

    int valread = read(cli1_fd, &codemsg, sizeof(uint32_t));
    if (valread <= 0) {
        perror("read");
        close(cli1_fd);
        return -1;
    }
    printf("SERVER: Code message received from client1: '%d'\n", codemsg);
    close(cli1_fd);

    /* decrementing codemsg and sending it to cli2 */
    codemsg--;
    int cli2_fd =
        accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
    if (cli2_fd < 0) {
        perror("accept");
        close(cli2_fd);
        return -1;
    }
    printf("SERVER: Sending code message '%d' to client2...\n", codemsg);
    int valwrite = write(cli1_fd, &codemsg, sizeof(uint32_t));
    if (valwrite < 0) {
        perror("send");
        close(cli2_fd);
        return -1;
    }
    close(cli2_fd);

    shutdown(server_fd, SHUT_RDWR);
}
