#include <stdio.h>

extern int loop_counter;

void nddisplay()
{
       printf("%d\n", ++loop_counter);
}