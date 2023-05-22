#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N_OF_RANDOM_NS 50
#define RAND_BETWEEN(min, max) (min + (rand() / (RAND_MAX / (max - min))))

int main()
{

    srand(time(0));

    printf("N of random numbers: %d\n", N_OF_RANDOM_NS);
    for (int i = 0; i < 50; i++)
        printf("%0.4f\n", RAND_BETWEEN(-0.5, 0.5));
}