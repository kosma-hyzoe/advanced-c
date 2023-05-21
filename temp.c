#include <stdio.h>

int main() {
    int num1, num2;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    // Clear the input buffer
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("First number: %d\n", num1);
    printf("Second number: %d\n", num2);

    return 0;
}