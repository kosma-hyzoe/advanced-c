#include <stdio.h>
#define MAX_BINARY_LENGTH 64

const char *dec_to_bin(int dec)
{
    char bin[] = {[0 ... MAX_BINARY_LENGTH - 1] = '0'} ;
    char *tmpbinptr = bin;

    if (dec < 0) {
        *(tmpbinptr++) = '-';
        dec *= -1;
    }

    int pos = 0;
    while (dec >= 1) {
        int remainder = dec % 2;
        if (remainder != 0)
            *tmpbinptr = '1'; 
        dec /= 2;
        tmpbinptr++;
    }

    *tmpbinptr='\0';   
    const char *out = bin;
    return out;
}

int main()
{
    int x, y;
    printf("x: ");
    scanf("%d", &x);

    printf("\ny: ");
    scanf("%d", &y);

    printf("Bitwise AND: %s\n", dec_to_bin(x & y));
    printf("Bitwise OR: %s\n", dec_to_bin(x | y));
    printf("Bitwise XOR: %s\n", dec_to_bin(x ^ y));
    printf("\nFlipped bits of x: %s\n", dec_to_bin(~x));
    printf("Left-shifting x by 5 bits: %s\n", dec_to_bin(x << 5));
    printf("Right-shifting y by 3 bits: %s\n", dec_to_bin(y >> 3));
}