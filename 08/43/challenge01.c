#include <string.h>
#include <stdio.h>
#include <math.h>

int bin_to_dec(char *bin)
{
    char c;
    int dec = 0, power = strlen(bin) - 1;
    while ((c = *(bin++)) != '\0') {
        if (c == '1')
            dec += (int) pow(2, power);
        power--;
    }

    return dec;
}

int main()
{
    char *bin = "10000100101001";
    printf("Decimal equivalent of 0b%s: %i\n", bin, bin_to_dec(bin));
}