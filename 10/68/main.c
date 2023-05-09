#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define _LINE_MAX 256

void fakegrep(FILE *fp, char *s)
{
    char buffer[_LINE_MAX];
    while (fgets(buffer, _LINE_MAX, fp) != NULL) {
        if (strstr(buffer, s))
            printf("%s", buffer); 
    }
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

    fakegrep(ifp, s);

    fclose(ifp);
}