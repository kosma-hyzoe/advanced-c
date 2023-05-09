#pragma once

#define BUFF_SIZE (int)(1 << 10)

int data[BUFF_SIZE];

struct BufId {
    unsigned int id;
};

typedef struct full_desc {

    void *ptr;
    size_t size;

    struct BufId *Id;

    const char *name;
    unsigned int offset;

} full_desc_t;

static inline void _ext_prepare_data();

void EXT_PREPARE_TASK1();

full_desc_t *EXT_GET_PTR();
