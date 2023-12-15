#include <stdio.h>

int dedouble(double n) { return (int)n; }

int main()
{
    int (*dedoubleptr)(double) = &dedouble;

    double n = 3.0;
    int dedoubled = (*dedoubleptr)(n);
    printf("%i\n", dedoubled);
}