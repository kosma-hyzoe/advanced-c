#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define IPV4_ADDR "127.0.0.1"

int main(int argc, char const *argv[])
{
    int cstatus, cli_fd;
    struct sockaddr_in serv_addr;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, IPV4_ADDR, &serv_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return -1;
    }

    if ((cli_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }

    cstatus = connect(cli_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (cstatus < 0) {
        perror("connect");
        close(cli_fd);
        return -1;
    }

    uint32_t codemsg;
    int valread = read(cli_fd, &codemsg, sizeof(uint32_t));
    if (valread <= 0) {
        perror("read");
        close(cli_fd);
        return -1;
    }

    printf("CLI12: Code message received from server: '%d'\n", codemsg);
    close(cli_fd);
    return 0;
}