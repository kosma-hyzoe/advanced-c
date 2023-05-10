
#include <stdlib.h>
#include <stdio.h>

#define BUFF_SIZE               (int)(1<<29)

typedef struct {
    char padding[3];
    short id;
    float factor;
    char depth;
} Flow1;

int
main()
{
    Flow1 *flow = malloc(BUFF_SIZE * sizeof(Flow1));

    flow[0].id = 0;
    flow[0].factor = 1e-3;
    flow[0].depth = 123;

    for (int i = 1; i < BUFF_SIZE; ++i)
    {
        flow[i].id = flow[i-1].id + 1;
        flow[i].factor = flow[i-1].factor + 1e-3;
        flow[i].depth = ( (unsigned char)flow[i-1].depth + (unsigned char)i ) % 129;
    }

    free(flow);
}
