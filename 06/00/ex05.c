#include <stdio.h>

int main(void)
{
	int i;
	printf("type a number and 'Enter'\n");
	scanf(" %d", &i);
    
    char *s = i == 5 ? "equal to" : (i > 5 ? "greater than" : "less than");
    printf("It's %s 5\n", s);
    
	printf("type a number and 'Enter'\n");
	scanf(" %d", &i);
    
    s = i < 10 ? (i > 5 ? "5 < i < 10" : "i <= 5") : "i >= 10";
    printf("%s\n", s);
}