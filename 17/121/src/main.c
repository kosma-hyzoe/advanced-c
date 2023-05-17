#include <stdio.h>
#include <stdlib.h>
#include "strfun.h"

int main()
{
    char foo[] = "f00b@r";
    char *bar = "fooobarbaz";
    char foobar[127] = "...";
    char baz[10];

    rmnonalpha(foo);
    printf("rmnonalpha(): %s\n", foo);

    printf("cfreq(): %d\n", cfreq(bar, 'o'));

    printf("mystrlen(): %ld\n", mystrlen(bar));
    printf("mystrstr(): %s\n", mystrstr(bar, "bar"));

    mystrcat(foobar, foo);
    mystrcat(foobar, bar);
    printf("mystrcat(): %s\n", foobar);

    printf("mystrcpy(): %s\n", mystrcpy(baz, bar));
}
