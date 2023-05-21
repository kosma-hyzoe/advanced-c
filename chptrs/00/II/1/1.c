#include "1_ext.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    EXT_PREPARE_TASK1();

    typedef struct {
        char *ptr;
        size_t size;
    } short_desc_t;

    short_desc_t short_desc;

    uint32_t index;

    {
        typedef struct {
            void *ptr;
            size_t size;
            void *Id;
        } desc_t;

        desc_t *desc = (desc_t *)EXT_GET_PTR();

        /* copy data from ``desc`` to ``short_desc`` and ``index`` */
        short_desc.ptr = desc->ptr;
        short_desc.size = desc->size;
        index = (( struct BufId *)desc->Id)->id;
        // code ends here
    }

    /* print out contents of ``short_desc`` */
    printf("short_desc: %s\n", short_desc.ptr);
    printf("short_desc.size: %li", short_desc.size);
    // code ends here

    return 0;
}
