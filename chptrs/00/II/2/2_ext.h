#pragma once

#include <stdint.h>
#include <stddef.h>
/* data types definition */
typedef struct {
    uint32_t height;
    uint32_t width;
    uint8_t bdepth;
    uint8_t color_type;
    uint8_t compression_method;
    uint8_t filter_method;
    uint8_t interlace_method;
} IHDR_t;

typedef struct {
    uint8_t intent;
} sRGB_t;

typedef struct {
    void *ptr;
    uint64_t size;
} IDAT_t;

struct Image {

    IHDR_t *IHDR;
    sRGB_t *sRGB;
    IDAT_t *IDAT;

    uint64_t id;
};

/* private methods */
/* private methods - end here */

/* public methods */
struct Image *ImageAllocate(void);

void ImageFree(struct Image *);

struct Image *ImageCopy(struct Image *);
