#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    int dec = 32769;

    printf("Binary equivalent of %i: %s\n", dec, dec_to_bin(dec));
}