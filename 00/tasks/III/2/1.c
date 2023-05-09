
#include <assert.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

static const char signature[] =
{ 0x41, 0x50, 0x45, 0x4F
};

bool
compare_strings(unsigned char *a, unsigned char *b, const size_t size)
{ /* empty */ assert(!"Not implemented!\n"); }

int
main()
{
    uint32_t val;
    /* compare contents of ``val`` and ``signature`` using ``comapre_strings`` method
     *
     * followup question:  how to compare ``val`` contents with signature contents without any loop ?
     * */
}
