#include <stdio.h>

int main()
{
	int arrsize;

	printf("Enter the desired array size: ");
	scanf("%i", &arrsize);

	int nums[arrsize];
        int sum = 0;

	for (int i = 0; i < arrsize; i++) {
		printf("Enter a number to insert at index '%d': ", i);
		scanf("%i", &nums[i]);
	}

        for (int i = 0; i < arrsize; i++)
                sum += nums[i];
        
        printf("Sum: %d\n", sum);
        
	return 0;
}