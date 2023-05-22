#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define OUT_PATH "out.txt"
#define TMP_PATH "tmp"

void fswitchcase(FILE *ifp, FILE *ofp)
{
    int c;
    while ((c = fgetc(ifp)) != EOF)
        islower(c) ? fputc(toupper(c), ofp) : fputc(tolower(c), ofp);
}

/* switch char case in a file provided in cmd arg or via user input */
int main(int argc, char *argv[])
{
    char *infname;
    if (argc == 2) {
        infname = argv[1];
    } else {
        infname = malloc(FILENAME_MAX);
        printf("File name:\n");
        fgets(infname, FILENAME_MAX, stdin);
        infname[strcspn(infname, "\n")] = '\0';
    }
    
    FILE *ifp = fopen(infname, "r");
    FILE *ofp = fopen(TMP_PATH, "w+");

    if (!ifp || !ofp) {
        printf("Cant open '%s'\n", !ifp ? infname : TMP_PATH);
        return 1;
    }

    fswitchcase(ifp, ofp);

    rename(TMP_PATH, OUT_PATH);

    fclose(ifp);
    fclose(ofp);
    return 0;
}
