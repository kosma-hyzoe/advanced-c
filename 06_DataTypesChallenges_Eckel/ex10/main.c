#include <stdio.h>

void print_int_arr_addresses(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%p\n", &arr[i]);
    printf("\n");
}

void print_char_arr_addresses(char arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%p\n", &arr[i]);
    printf("\n");
}

int main()
{
    printf("Int array addresses:\n\n");
    int arr_a[10];
    print_int_arr_addresses(arr_a, sizeof(arr_a)/sizeof(int));


    char arr_b[10];
    print_char_arr_addresses(arr_b, 10);
    printf("Char array addresses:\n\n");

    void (*piaaptr)(int [], int) = &print_int_arr_addresses;
    void (*pcaaptr)(char [], int) = &print_char_arr_addresses;

    (*piaaptr)(arr_a, 10);
    (*pcaaptr)(arr_b, 10);
}
