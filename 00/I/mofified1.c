#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Data {
    char *buf;
    size_t size;

    unsigned int id;
    const char *name;
};
struct Data data;

void
DataSetup()
{
    
}


int
main()
{
    const size_t size = 1024;
    void *ptr = data.buf;

    data.size = size;
    ptr = malloc(size);
    memset(ptr,123,size);                       /* <-  przypisanie wartosci do arraya */
    data.id = 3;
    data.name = "First Instance";
    void *buf;

    
        char *ptr2 = malloc(123);
        ptr2 = (char*)(struct Data*)&data;
        ptr2 += 8;

        memset( (char*)ptr2, 0, sizeof(long long));  /* co spowoduje ta operacja */
        *ptr2 = 148;
        ptr2[1] = 1;

        // buf = data.buf;
    

    // printf("%c\n", *(char*)buf); /* co zostanie wyprintowane na ekran? */

    return 0;
}

