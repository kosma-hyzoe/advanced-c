#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define _LINE_MAX 256
#define ROW_WIDTH 4
#define ROW_MAX 256

void scanns(FILE *fp)
{
    int ns[ROW_MAX][ROW_WIDTH];
    int i = 0;
    while ((fscanf(fp, "%d\t%d\t%d\t%d\t", &ns[0][0], &ns[0][1], &ns[0][2],
                   &ns[0][3])) == 4)
        i++;
}

int main(int argc, char *argv[])
{
    if (argc != 3) {
        printf("Invalid command line args - exiting...\n");
        return 1;
    }

    char *infname = argv[1], *s = argv[2];
    FILE *ifp = fopen(infname, "r");
    if (!ifp) {
        printf("Cant open '%s' - exiting...\n", infname);
        return 1;
    }

    scanns(ifp);

    fclose(ifp);
}