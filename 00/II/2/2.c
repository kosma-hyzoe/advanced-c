/* przetestowac dzialanie */

#include "2_ext.c"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>


int main()
{
    struct Image *image = ImageAllocate();

    image->id = 1;
    image->IHDR->height = 500;
    image->IHDR->width = 500;
    image->IHDR->bdepth = 16;
    image->IHDR->color_type = 2;
    image->IHDR->compression_method = 0;
    image->IHDR->filter_method = 0;
    image->IHDR->interlace_method = 0;

    image->sRGB->intent = 0;

    image->IDAT->size = 1000;
    image->IDAT->ptr = malloc(1000);

    struct Image *imagecp = ImageCopy(image);

    assert(imagecp->id == image->id);
    assert(imagecp->IHDR->height == image->IHDR->height);
    assert(imagecp->IHDR != image->IHDR);
    
    ImageFree(image);
    ImageFree(imagecp);

    return 0;
}
