#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 20
#define RAND_BETWEEN(min, max) (min + (rand() / (RAND_MAX / (max - min))))

void fillarray(double ar[], int n)
{
    for (int i = 0; i < n; i++)
        ar[i] = RAND_BETWEEN(1, 100);
}

void showarray(double ar[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%i ", (unsigned int) ar[i]);
    printf("\n");
}

int double_cmp(const void * a, const void * b) {
   return ( *(double*)a - *(double*)b );
}

/* sorts array of doubles from lowest to highest */
int main()
{
    srand(time(0));
    double ar[ARRAY_SIZE];

    printf("Before sorting:\n");
    fillarray(ar, ARRAY_SIZE);
    showarray(ar, ARRAY_SIZE);

    printf("\nAfter sorting:\n");
    qsort(ar, ARRAY_SIZE, sizeof(double), double_cmp);
    showarray(ar, ARRAY_SIZE);
}