#include <stdio.h>

void nddisplay();

int loop_counter = 0;

int main()
{
	for (; loop_counter < 5;)
                nddisplay();

	return 0;
}