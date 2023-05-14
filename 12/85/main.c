#include <stdio.h>

union student {
    char letter_grade;
    int rounded_grade;
    float exact_grade;
};

union foobar {
    int foo;
    float bar;
} baz;

struct boofar {
    int baz;
    union {
        int boo;
        float far;
    }
};

int main()
{
    union student foobian, barsky;

    foobian.exact_grade = 3.5;
    foobian.rounded_grade = 4;
    foobian.letter_grade = 'B';
    printf("%d\n", foobian.exact_grade);
    printf("%i\n", foobian.rounded_grade);
    printf("%c\n", foobian.letter_grade);

    barsky.exact_grade = 2.3;
    printf("%d\n", barsky.exact_grade);
    barsky.rounded_grade = 2;
    printf("%i\n", barsky.rounded_grade);
    barsky.letter_grade = 'E';
    printf("%c\n", barsky.letter_grade);

    union foobar bazaar = {.foo = 3.14};
}