#include <stdio.h>

void display();

int loop_counter = 0;

int main()
{
	for (; loop_counter < 5;)
                display();

	return 0;
}