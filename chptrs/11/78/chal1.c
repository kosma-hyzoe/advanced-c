#include <stdio.h>

int sum(int n)
{
    int s = 0;

    if (n == 1)
       return 1;
    else
        s = n + sum(--n); 

    return s;
}

int findgcd(int n1, int n2)
{
    while (n1 != n2) 
        return n1 > n2 ? findgcd(n1-n2, n2) : findgcd(n1, n2-n1); 
    return n1;
}

int main()
{
    printf("%d\n", sum(5));
}