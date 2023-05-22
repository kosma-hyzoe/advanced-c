#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <unistd.h>

#define GET_RAND() (4 + (rand() / (RAND_MAX / (12 - 4))))

volatile sig_atomic_t termflag = 0;

void settermflag(int sig) { termflag = 1; }

int main()
{
    srand(time(NULL));

    struct sigaction sa;
    sa.sa_handler = settermflag;
    sa.sa_flags = 0; /* no special flags */
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    if (sigaction(SIGALRM, &sa, NULL) == -1) {
        perror("sigaction");
        exit(1);
    }

    int ccorrect = 0;
    while (!termflag) {
        int x = GET_RAND(), y = GET_RAND();
        int ans;

        printf("%d x %d = ", x, y);

        alarm(5);
        if (scanf("%d", &ans) == EOF)
            break;
        alarm(0);

        if (x * y == ans)
            ccorrect++;
    }
    printf("Correct answers: %d\n", ccorrect);
}
