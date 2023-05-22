#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i = 108;
    int *ip = &i;
    int **ipp = &ip;
    /* value of int */
    printf("Value of i by value: %d\n", i);
    printf("Value of i by pointer dereference: %d\n", *ip);
    printf("Value of i by double pointer double dereference: %d\n", **ipp);
    /* address of int */
    printf("\nAddres of i by value: %p\n", &i);
    printf("Addres of i by pointer: %p\n", ip);
    printf("Addres of i by double pointer: %p\n", *ipp);
    /* value of pointer */
    printf("\nValue of pointer by pointer: %p\n", ip);
    printf("Value of pointer by double pointer deredrence: %p\n", *ipp);
    printf("Value of pointer by value address: %p\n", &i);
    /* address of pointer */
    printf("\nAddress of pointer by pointer address: %p\n", &ip);
    printf("Address of pointer by double pointer: %p\n", ipp);
    /* double pointer value and address */
    printf("\nDouble pointer value: %p\n", ipp);
    printf("Double pointer value by address-of-dereference shenanigans: %p\n", &(*ipp));
    printf("Address of double pointer: %p\n", &ipp);

}