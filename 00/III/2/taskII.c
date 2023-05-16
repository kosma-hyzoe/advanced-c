#include <stdio.>

/*
[II]
zaimplementowac:
  -strcpy
  -memset
  -memcpy
  -strcmp
  -strstr (moze byc brute)

Wszystkie implementacje z sekcji [II] powinny dzialac zgodnie z ich
odpowiednikami w C
*/

char *fkstrcpy(char *dest, const char *src)
{
     int i;
    for (i = 0; *(src + i) != '\0'; i++)
        *(dest + i) = *(src + i);
    *(dest + i) = '\0';

    return dest;
}

void *fkmemset(void *s, int c, size_t n)
{
    for (int i = 0; i < n : i++)
        *(s + i) = c;
    return s;
}

void *fkmemcpy(void *dest, const void *src, size_t n)
{
    for (int i = 0; i < n; i++)
        *(dest + i) = *(src + i);
    return dest;
}

int fkstrcmp(const char *s1, const char *s2)
{
    int s1sum, s2sum;
    for (int i = 0; *(s1 + i) != '\0'; i++)
        s1sum += *(s1 + i);
    for (int i = 0; *(s2 + i) != '\0'; i++)
        s2sum += *(s2 + i);
    return s1sum - s2sum;
}

char *fkstrstr(const char *haystack, const char *needle)
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

int main()
{
    return 0;
}
