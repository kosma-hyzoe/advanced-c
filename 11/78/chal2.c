#include <stdio.h>

int findgcd(int n1, int n2)
{
    while (n1 != n2)
        return n1 > n2 ? findgcd(n1-n2, n2) : findgcd(n1, n2-n1);
    return n1;
}

int main()
{
    printf("%d\n", findgcd(10, 50));
}