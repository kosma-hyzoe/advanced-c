#include <stdio.h>

#define BLACK 0
#define RED 1
#define GREEN 2
#define YELLOW 3
#define BLUE 4
#define MAGENTA 5
#define CYAN 6
#define WHITE 7

#define SOLID 0
#define DOTTED 1
#define DASHED 2

struct obox {
    unsigned int : 2;
    unsigned int transparent : 1;
    unsigned int hideborder : 1;
    unsigned int fillcolor : 3;
    unsigned int bordercolor : 3; // 8 colors, 2**3
    unsigned int borderstyle : 2; // 3 styles
};

int main(int argc, char const *argv[])
{

    struct obox gbox = {0, 0, GREEN, GREEN, SOLID};
    printf("obox: %i\t%i\t%i\t%i\t%i\n", gbox.transparent, gbox.hideborder,
           gbox.fillcolor, gbox.bordercolor, gbox.borderstyle);
    
    gbox = (struct obox) {1, 1, BLACK, BLUE, DOTTED};
    printf("obox: %i\t%i\t%i\t%i\t%i\n", gbox.transparent, gbox.hideborder,
           gbox.fillcolor, gbox.bordercolor, gbox.borderstyle);
}
