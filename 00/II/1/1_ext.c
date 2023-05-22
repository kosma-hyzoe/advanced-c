
#include <stdlib.h>
#include <string.h>
#include "1_ext.h"

int data[BUFF_SIZE];
static const char *name = "ABCDEFGH";

static inline void
_ext_prepare_data()
{
    memcpy((char*)data,name, strlen(name));
}

void
EXT_PREPARE_TASK1()
{
    _ext_prepare_data();
}

full_desc_t*
EXT_GET_PTR()
{
    full_desc_t *desc = calloc(1, sizeof(full_desc_t));
    desc->Id = calloc(1, sizeof desc->Id);

    desc->ptr = (void*) ((char*)data + 2);
    desc->size = strlen(name) - 2;
    desc->Id->id = 12;

    return desc;
}
