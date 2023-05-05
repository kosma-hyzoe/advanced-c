#include <stdio.h>

void func(void)
{
    static int x = 0;
    x = x ? x + 2 : x + 1;
    printf("%i\n", x);
}

int main()
{
    int max;
    printf("max = ");
    scanf(" %d", &max);
    int i;
    for (i = 0; i < max; ++i) 
        func();
}
