#include <stdio.h>

#define N_OF_COLORS 5

#define TO_STR(c) ((c) == RED ? "RED" : \
        (c) == GREEN ? "GREEN" : \
        (c) == BLUE ? "BLUE" : \
        (c) == WHITE ? "WHITE" : \
        (c) == BLACK ? "BLACK" : \
        "UNKNOWN")

enum colors { RED, GREEN, BLUE, WHITE, BLACK };

int main()
{
    for (int i = 0; i < N_OF_COLORS; i++) {
        enum colors clr = (enum colors) i;
        printf("Color: %s\n", TO_STR(clr));
    }

    return 0;
}
