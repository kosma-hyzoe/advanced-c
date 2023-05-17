#include <stdarg.h>
#include <stdio.h>

int sum(int count, ...)
{
    int s = 0;
    va_list ns;
    va_start(ns, count);
    for (int i = 0; i < count; i++) {
        int arg = va_arg(ns, int);
        s += arg;
    }
    va_end(ns);
    return s;
}

int main()
{
     printf("%d\n", sum(3, 30, 15, 5));
}