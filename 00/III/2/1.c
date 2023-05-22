
#include <assert.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

static const char signature[] = {0x41, 0x50, 0x45, 0x4F};

bool compare_strings(unsigned char *a, unsigned char *b, const size_t size)
{
    for (int i = 0; i < size; i++) {
        if (*(a + i) != *(b + i))
            return false;
    }
    return true;
}
/*
 * you could also try this:
 *
 * uint64_t *p1 = (uint64_t *)str1;
 * uint64_t *p2 = (uint64_t *)str2;
 * bool equal = *p1 == *p2 ? true : false;
 */
bool cmp_strings_no_loops(unsigned char *a, unsigned char *b, const size_t size)
{
    if (memcmp(a, b, size) == 0)
        return true;
    else
        return false;
}

int main()
{
    uint32_t val = 0x4f455041;
    unsigned char *valptr = (unsigned char *)&val;

    printf("%d\n", compare_strings(signature, valptr, 4));
    /* compare contents of ``val`` and ``signature`` using ``comapre_strings``
     * method
     *
     * followup question:  how to compare ``val`` contents with signature
     * contents without any loop ?
     * */
}
