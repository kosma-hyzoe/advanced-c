#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define IPV4_ADDR "127.0.0.1"

int main(int argc, char const *argv[])
{
    int status, valread, cli_fd;

    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, IPV4_ADDR, &serv_addr.sin_addr) <= 0) {
        printf("\nInvalid address. Exiting... \n");
        return -1;
    }

    int32_t *msg;
    printf("Enter the int you'd like to send to server: ");
    scanf("%d", &msg);


    if ((cli_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    int s = connect(cli_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if ((s < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    uint32_t *response;
    write(cli_fd, msg, strlen(msg), 0);
    valread = read(cli_fd, &response, sizeof(uint32_t));
    printf("Server response: %d\n", response);

    close(cli_fd);
    return 0;
}
