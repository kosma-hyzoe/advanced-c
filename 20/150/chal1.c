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
    signal(SIGINT, settermflag);
    signal(SIGALRM, settermflag);

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
    printf("\nCorrect answers: %d\n", ccorrect);
}