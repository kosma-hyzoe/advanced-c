#include <string.h>
#include <stdio.h>
#include <math.h>

int bin_to_dec(char *bin)
{
    char c;

    int is_negative = 0;
    if (*bin == '-') {
        is_negative = 1;
        bin++;
    }

    int dec = 0, power = strlen(bin) - 1;
    while ((c = *(bin++)) != '\0') {
        if (c == '1')
            dec += (int) pow(2, power);
        power--;
    }

    return is_negative ? dec * -1 : dec;
}

int main()
{
    char *bin = "-10000100101001";
    printf("Decimal equivalent of %s: %i\n", bin, bin_to_dec(bin));
}