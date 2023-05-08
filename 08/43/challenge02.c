#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BINARY_LENGTH 64

const char *dec_to_bin(uint dec)
{
    char bin[] = {[0 ... MAX_BINARY_LENGTH - 1] = '0'} ;
    char *tmpbinptr = bin;

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
    int dec = 32769;

    printf("Binary equivalent of %i: 0b%s\n", dec, dec_to_bin(dec));
}