#include <stdio.h>

extern int loop_counter;

void display()
{
       printf("%d\n", ++loop_counter); 
}