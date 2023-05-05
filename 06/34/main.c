#include <stdio.h>
#include <stdlib.h>

struct myarray {
    int length;
    int array[];
};

int main()
{
    int s;
    struct myarray *maptr;

    printf("Enter the desired array size: ");
    scanf("%i", &s);

    maptr = malloc(sizeof(struct myarray) + s * sizeof(int));
    maptr->length = s;

    for (int i = 0; i < s; i++) {
        if (i < 2)
            maptr->array[i] = i;
        else
            maptr->array[i] = maptr->array[i - 1] + maptr->array[i - 2];
        printf("%i\n", maptr->array[i]);
    }

	free(maptr);

    return 0;
}