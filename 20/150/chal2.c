#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

#define NCHILDREN 3

int main()
{
    printf("Parent process  : PID %d\tPPID %d\n", getpid(), getppid());

    for (int i = 1; i <= NCHILDREN; i++) {
        pid_t pid = fork();
        if (pid > 0)
            break;
        else if (pid == -1)
            return -1;

        printf("Child  process %d: PID %d\tPPID %d\n", i, getpid(), getppid());
    }
}
