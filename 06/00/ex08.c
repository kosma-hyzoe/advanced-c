#include <stdio.h>

void print_arr(int arr[], int size, char *name)
{
    printf("Array size: %d\n", size);

    printf("Array elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\nArray name: %s\n\n", name);
}

void last_el_to_sum(int *arrptr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += *(arrptr++);

    *(arrptr-1) = sum;
}

int main()
{
    int foo[] = {1, 2, 3, 4, 5};
    int fib[] = {0, 1, 1, 2, 3};
    int size = sizeof(foo) / sizeof(int);


    print_arr(foo, size, "Foobar");
    print_arr(fib, size, "Fibonacci");

    printf("\nAfter changing last element to sum:\n\n\n");

    last_el_to_sum(foo, size);
    last_el_to_sum(fib, size);

    print_arr(foo, size, "Foobar");
    print_arr(fib, size, "Fibonacci");
}