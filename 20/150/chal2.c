#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    printf("Parent process  : PID %d\tPPID %d\n", getpid(), getppid());

    for (int i = 1; i < 4; i++) {
        pid_t pid = fork();
        if (pid > 0)
            break;

        printf("Child  process %d: PID %d\tPPID %d\n", i, getpid(), getppid());
    }
}