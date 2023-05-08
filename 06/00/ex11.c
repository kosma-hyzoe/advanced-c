#include <stdio.h>

void print_arr(int arr[], int size)
{
    for (int i = 0; i < size; i++) {
        printf("value %i at index %i and address %p\n", arr[i], i, &arr[i]);
    }
    printf("\n");
}

void modify_arr_element(void *arrptr, int index, int value)
{
    *((int *)arrptr + index) = value;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    print_arr(arr, 5);

    modify_arr_element(&arr, 2, 108);
    print_arr(arr, 5);
}