#include <stdio.h>
#define N_OF_COLORS 5

enum colors { RED, GREEN, BLUE, WHITE, BLACK };


char* get_color_str(enum colors color)
{
    static char *strreprs[]  = {"Red", "Green", "Blue", "White", "Black"};
    return strreprs[color];
}

int main()
{
    for (int i = 0; i < N_OF_COLORS; i++) {
        enum colors clr = (enum colors) i;
        printf("Color: %s\n", get_color_str(clr));
    }

    return 0;
}
