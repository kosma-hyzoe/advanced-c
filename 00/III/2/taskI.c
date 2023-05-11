#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

void rev_bytes(unsigned char *b, size_t c)
{
    size_t i;
    for (i = 0; i < c / 2; i++) {
        unsigned char t = b[i];
        b[i] = b[c - 1 - i];
        b[c - 1 - i] = t;
    }
}

int main(void)
{
    {
        unsigned char foo = 'a';
        unsigned char bar = 'b';
        unsigned char foobar[] = {foo, bar};
        rev_bytes(foobar, 2);
        printf("%c%c\n", foobar[0], foobar[1]);
    }
    {
        unsigned int buf = 65408;
        rev_bytes((char *)&buf, 2);
        printf("0x%02X\n ", buf);
    }
    {
        unsigned long long buf = 65408044440ll;
        rev_bytes((char *)&buf, 2);
        printf("0x%02llX\n ", buf);
    }
    {
        typedef struct {
            uint32_t height;
            uint32_t width;
            uint8_t bdepth;
            uint8_t color_type;
            uint8_t compression_method;
            uint8_t filter_method;
            uint8_t interlace_method;
        } IHDR_t;

        IHDR_t foo = {255, 300, 0, 3, 4, 4, 4};
        rev_bytes((char *)&foo, sizeof(IHDR_t));    
    }
    {
        int i;
        unsigned char buf[16] = {0x0, 0x8, 0x4, 0xC, 0x2, 0xA, 0x6, 0xE,
                                 0x1, 0x9, 0x5, 0xD, 0x3, 0xB, 0x7, 0xF};

        rev_bytes(buf, 16);

        for (i = 0; i < 16; i++)
            printf("0x%02X ", buf[i]);
        printf("\n"); 
    }
    {
        /* seg fault... not sure why */
        unsigned char * foo = "foobar";
        rev_bytes(foo, 6);
        printf("%s\n", foo);
    }

    return 0;
}