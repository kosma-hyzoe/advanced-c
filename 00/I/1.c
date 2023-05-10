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

inline void
DataSetup()
{
    const size_t size = 1024;
    void *ptr = data.buf;

    data.size = size;
    ptr = malloc(size);
    memset(ptr,123,size);                       /* <-  przypisanie wartosci do arraya */
    data.id = 3;
    data.name = "First Instance";
}


int
main()
{
    void *buf;

    {
        char *ptr = malloc(123);
        ptr = (char*)(struct Data*)&data;
        ptr += 8;

        memset( (char*)ptr, 0, sizeof(long long));  /* co spowoduje ta operacja */
        *ptr = 148;
        ptr[1] = 1;

        // buf = data.buf;
    }

    // printf("%c\n", *(char*)buf); /* co zostanie wyprintowane na ekran? */

    return 0;
}

