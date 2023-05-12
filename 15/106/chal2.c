#include <stdio.h>
#include <stdlib.h>

#ifndef DEBUG
#define DEBUG 0
#endif

#if DEBUG > 0
 #define DEBUG_PRINT(fmt, args...) fprintf(stderr, "DEBUG: %s:%d:%s(): " fmt, \
 __FILE__, __LINE__, __func__, ##args)
#else
 #define DEBUG_PRINT(fmt, args...)
#endif

int sum(int x, int y, int z)
{
    char c = 2;

    int *a = NULL;
    if (DEBUG > 1) {
        DEBUG_PRINT("Params:\n");
        fprintf(stderr, " x=%d\n", x);
        fprintf(stderr, " y=%d\n", y);
        fprintf(stderr, " z=%d\n", z);
        fprintf(stderr, " a=%ld\n", (long)a);
    }
    *a = 5;

    fprintf(stderr, "*a=%d\n", *a);

    return (c + x + y + z + *a) / 3;
}

int main(int argc, char *argv[])
{
    DEBUG_PRINT("Debugging is enabled.\n");
    DEBUG_PRINT("Debug level: %d\n", (int)DEBUG);
    int i, j, k;
    int result;

    #if DEBUG > 0
     fprintf(stderr, "Number of parameters = %d\n", argc);
    #endif

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
