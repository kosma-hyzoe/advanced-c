#include "2_ext.h"
#include <stdlib.h>
#include <string.h>

struct Image *ImageAllocate(void)
{
    struct Image *image = (struct Image *)malloc(sizeof(struct Image));

    if (image == NULL) {
        return NULL;
    }

    image->id = 1;
    image->IHDR = (IHDR_t *)malloc(sizeof(IHDR_t));
    image->sRGB = (sRGB_t *)malloc(sizeof(sRGB_t));
    image->IDAT = (IDAT_t *)malloc(sizeof(IDAT_t));

    if (image->IHDR == NULL || image->sRGB == NULL || image->IDAT == NULL) {
        ImageFree(image);
        return NULL;
    }

    image->IHDR->height = 0;
    image->IHDR->width = 0;
    image->IHDR->bdepth = 0;
    image->IHDR->color_type = 0;
    image->IHDR->compression_method = 0;
    image->IHDR->filter_method = 0;
    image->IHDR->interlace_method = 0;

    image->sRGB->intent = 0;

    image->IDAT->ptr = NULL;
    image->IDAT->size = 0;

    return image;
}

void ImageFree(struct Image *image)
{
    if (image->IHDR != NULL) {
        free(image->IHDR);
        image->IHDR = NULL;
    }
    if (image->sRGB != NULL) {
        free(image->sRGB);
        image->sRGB = NULL;
    }
    if (image->IDAT != NULL) {
        free(image->IDAT);
        image->IDAT = NULL;
    }
    free(image);
}

struct Image *ImageCopy(struct Image *image)
{
    struct Image *imagecp = ImageAllocate();
    if (imagecp == NULL)
        return NULL;

    imagecp->id = image->id;
    
    memcpy(imagecp->IHDR, image->IHDR, sizeof(IHDR_t));
    memcpy(imagecp->sRGB, image->sRGB, sizeof(sRGB_t));

    imagecp->IDAT->size = image->IDAT->size;
    if (imagecp->IDAT->size > 0) {
        imagecp->IDAT->ptr = malloc(imagecp->IDAT->size);
        if (imagecp->IDAT->ptr == NULL) {
            ImageFree(imagecp);
            return NULL;
        }
        memcpy(imagecp->IDAT->ptr, image->IDAT->ptr, imagecp->IDAT->size);
    }
    
    return imagecp;
}
