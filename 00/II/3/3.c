
/*
 * zmodyfikowac zawartosc danych w buforze ``corrupted_buf`` wedlug schematu:
 * 1. dla kazdego bajta:   [indeksacja 0-7 !]
 *   - 0. bit kazdego bajta- ustawic na 0
 *   - 2-3 bity - zamienic miejscami z bitami 6-7
 *
 * 2. zamienic kolejnosc bajtow w slowach 4 bajtowych od 0 do ``size``-1
 *    +slowa czytane wedlug LSB zamienic na MSB  (1. slowo rozpoczyna sie od
 * 0. bajtu) np. dla slowa:       12 34 56 78 po zamiannie:  78 56 34 12 dla
 * ``corrupted_buf``:       12 34 56 78 90 09 poprawna zamiana to:      78
 * 56 34 12 90 09 (tj. ostatnie dwa bajty nie zostaly zamienione poniewac
 * nie da utworzyc sie z nich slowa 4 bajtowego)
 */

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUF_SIZE 8
#define WORD_SIZE 4
#define UNSET_BIT_0_MASK 0xFE
#define MASK_BITS_2_3 0x0C
#define MASK_BITS_6_7 0xC0
#define MASK_BITS_2_3_AND_6_7 0x33

void switch_bits_2_3_to_6_7(uint8_t *byteptr)
{
    // get bytes
    unsigned char bits_2_3 = (*byteptr & MASK_BITS_2_3) << 4;
    unsigned char bits_6_7 = (*byteptr & MASK_BITS_6_7) >> 4;

    // clear byes 2-3 and 6-7
    *byteptr &= MASK_BITS_2_3_AND_6_7;

    // set bytes
    *byteptr |= bits_6_7 | bits_2_3;
}

void reverse_word_bytes(char *s, int size)
{
    for (int i = 0; i < (size / 2); i++) {
        char temp = s[i];
        s[i] = s[size - i - 1];
        s[size - i - 1] = temp;
    }
}

int main()
{
    typedef struct {
        void *corrupted_buf;
        size_t size;
    } local_data_t;

    /* 1. */
    local_data_t data = {malloc(sizeof(BUF_SIZE)), BUF_SIZE};
    {
        char word[BUF_SIZE] = "cdefgabc";
        data.corrupted_buf = word;
        printf("%s\n", (char *)data.corrupted_buf);
        for (int i = 0; i < BUF_SIZE; i++) {
            uint8_t *byteptr = (char *)(data.corrupted_buf) + i;
            *byteptr &= UNSET_BIT_0_MASK;
            switch_bits_2_3_to_6_7(byteptr);
        }
        printf("%s\n", (char *)data.corrupted_buf);
    }
    /* 2. */
    {
        char word[BUF_SIZE] = "cdefgabc";
        data.corrupted_buf = word;
        printf("%s\n", (char *)data.corrupted_buf);
        reverse_word_bytes(data.corrupted_buf, WORD_SIZE);
        printf("%s\n", (char *)data.corrupted_buf);
    }
}
