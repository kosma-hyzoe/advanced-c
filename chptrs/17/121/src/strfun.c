#include <stddef.h>
#include "../incl/strfun.h"

int cfreq(char *s, char c)
{
    int freq = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == c)
            freq++;
    }
    return freq;
}

int rmnonalpha(char *src)
{
    int i = 0, j = 0;
    while (src[i] != '\0') {
        if (BETWEEN(src[i], 'A', 'Z') || BETWEEN(src[i], 'a', 'z'))
            src[j++] = src[i];
        i++;
    }

    src[j] = '\0';
    return 0;
}

size_t mystrlen(const char *s)
{
    size_t len = 0;
    while (s[len])
        len++;
    return len;
}

char *mystrstr(const char *haystack, const char *needle)
{
    if (*needle == '\0')
            return (char *) haystack;

    for (int i = 0; *(haystack + i) != '\0'; i++) {
        if (*(haystack + i) == *needle) {
            int j = 0;
            while (*(needle + j) != '\0' && *(needle + j) == *(haystack + i + j))
                j++;
            if (*(needle +j) == '\0')
                return (char *)(haystack + i);
        }
    }
    return NULL;
}

char *mystrcat(char *dest, const char *src)
{
    // move the pointer to the end of the dest
    char *ptr = dest;
    while (*ptr != '\0')
        ptr++;

    while (*src != '\0')
        *(ptr++) = *(src++);

    *ptr = '\0';

    return dest;
}

char *mystrcpy(char *dest, const char *src)
{
    int i;
    for (i = 0; *(src + i) != '\0'; i++)
        *(dest + i) = *(src + i);
    *(dest + i) = '\0';

    return dest;
}
