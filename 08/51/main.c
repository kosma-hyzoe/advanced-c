#include <stdio.h>

#define MASK

int main()
{
    int n;
    printf("Your number: ");
    scanf("%d", &n);

    int mn, mask;
    printf("Enter the bit to check and set: ");
    scanf("%d", &mn);
    mask =  1 << mn;

    if ((n & mask) != mask) {
        printf("Number before setting the bit: %i\n", n);
        n |= mask;
        printf("Number after setting the bit: %i\n", n);
    } else {
        printf("This bit is already set.\n");
    }
}