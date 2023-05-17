#include <ctype.h>
#include <stdio.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

/* count words, and characters in file input or stdin */
int main(int argc, char const *argv[])
{
    int c, nw, nc, state;
    state = OUT;
    nw = nc = 0;
    if (argc == 2) {
        const char *fname = argv[1];
        FILE *in = fopen(fname, "r");
        if (!in) {
            printf("Can't read file '%s'... Exiting. \n", fname);
            return 1;
        }

        while ((c = fgetc(in)) != EOF) {
            ++nc;
            if (isspace(c))
                state = OUT;
            else if (state == OUT && isalpha(c)) {
                state = IN;
                ++nw;
            }
        }
        fclose(in);
    } else if (argc == 1){
        printf("Your input:\n");
        while ((c = getchar()) != EOF) {
            ++nc;
            if (isspace(c))
                state = OUT;
            else if (state == OUT && isalpha(c)) {
                state = IN;
                ++nw;
            }
        }
    } else {
        printf("Invalid command line arguments.\n");
        return 1;
    }
    printf("%d %d\n", nw, nc);
}
