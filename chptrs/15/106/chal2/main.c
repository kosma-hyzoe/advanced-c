#include <stdio.h>
#include <stdlib.h>

#ifndef DEBUG
#define DEBUG 0
#endif

#define DBG_PRINT(lvl, fmt, args...) ((DEBUG >= lvl) ? \
                      fprintf(stderr, "DEBUG: %s:%d:%s(): " fmt, \
                      __FILE__, __LINE__, __func__, ##args) \
                      : (void)0)


int sum(int x, int y, int z)
{
    char c = 2;

    int *a = NULL;
    DBG_PRINT(1, "\nParams:\n\tx=%d\n\ty=%d\n\tz=%d\n\ta=%ld\n", x, y, z, (long)a);
    *a = 5;

    fprintf(stderr, "*a=%d\n", *a);

    return (c + x + y + z + *a) / 3;
}

int main(int argc, char *argv[])
{
    DBG_PRINT(1, "Debugging is enabled.\n");
    DBG_PRINT(1,"Debug level: %d\n", (int)DEBUG);
    int i, j, k;
    int result;

    fprintf(stderr, "Number of parameters = %d\n", argc);
    if (argc == 1) {
        printf("Please specify three numbers as parameters.\n");
        exit(1);
    }
    i = atoi(argv[1]);
    fprintf(stderr, "i=%d\n", i);
    j = atoi(argv[2]);
    fprintf(stderr, "j=%d\n", j);
    k = atoi(argv[3]);
    fprintf(stderr, "k=%d\n", k);
    result = sum(i, j, 12) + sum(j, k, 19) + sum(i, k, 13);
    printf("%d\n", result);

    return 0;
}
