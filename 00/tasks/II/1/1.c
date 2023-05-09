#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "1_ext.h"

int
main()
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

        desc_t *desc = (desc_t*) EXT_GET_PTR();
        printf("foo\n");
        /* copy data from ``desc`` to ``short_desc`` and ``index`` */

        // code ends here
    }

    /* print out contents of ``short_desc`` */
    // code ends here

    return 0;
}
