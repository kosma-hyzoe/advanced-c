#include <stdio.h>

char * revstr(char *s)
{
    static int i = 0;
    static char revs[100];

    if (*s) {
        revstr(s + 1);
        revs[i++] = *s;
    }

    return revs;
}

int main()
{
    char foobar[] = "foobar";
    printf("%s\n", revstr(foobar));
}
