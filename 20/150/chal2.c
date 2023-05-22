#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>


int main()
{
    pid_t pid1 = fork();
    pid_t pid2 = fork(); /* child1 will create a grandchild, child3 */

    if (pid1 > 0 && pid2 > 0) {
        printf("Parent process  : PID %d\tPPID %d\n", getpid(), getppid());
    } else {
        int cc = (pid1 == 0 && pid2 > 0) ? 1 : (pid1 > 0 && pid2 == 0) ? 2 : 3;
        printf("Child  process %d: PID %d\tPPID %d\n", cc, getpid(), getppid());
    }
    return 0;
}