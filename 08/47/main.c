#include <stdio.h>
#define MAX_BINARY_LENGTH 64

const char *dec_to_bin(int dec)
{
    char bin[] = {[0 ... MAX_BINARY_LENGTH - 1] = '0'} ;
    char *tmpbinptr = bin + MAX_BINARY_LENGTH - 1;


    int is_negative = (dec < 0) ? 1 : 0;
    dec = (dec < 0) ? dec * -1 : dec;
    
    while (dec >= 1) {
        int remainder = dec % 2;
        if (remainder != 0)
            *tmpbinptr = '1'; 
        dec /= 2;
        tmpbinptr--;
    }

    if (is_negative)
        *(tmpbinptr) = '-';
    else
        tmpbinptr++;

    char *out = tmpbinptr;

    return out;
}

int main()
{
    int x, y;
    printf("x: ");
    scanf("%d", &x);

    printf("y: ");
    scanf("%d", &y);

    printf("Flipped bits of x: %s\n", dec_to_bin(~x));
    printf("Bitwise AND: %s\n", dec_to_bin(x & y));
    printf("Bitwise OR: %s\n", dec_to_bin(x | y));
    printf("Bitwise XOR: %s\n", dec_to_bin(x ^ y));
    printf("Left-shifting x by 5 bits: %s\n", dec_to_bin(x << 5));
    printf("Right-shifting y by 3 bits: %s\n", dec_to_bin(y >> 3));
}