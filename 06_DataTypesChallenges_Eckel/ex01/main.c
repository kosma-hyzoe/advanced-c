#include <stdio.h>

int main()
{
    for (int num = 1; num <= 100; num++) {

        int divisor = 2;
        for (; divisor <= num; divisor++)
            if (num % divisor == 0)
                break;
        
        if (num == divisor)
            printf("%i\n", num);
    }
}
