#include <stdio.h>
#include <malloc.h>

void ppalloc(int **ipp) {*ipp = malloc(sizeof(__int32_t)); }

int main()
{
    int *ip = NULL;
    ppalloc(&ip);
    *ip = 30500;
    printf("*ip: %d\n", *ip);
    free(ip);
}