#include <stdio.h>

#define IS_UPPER(x) (x >= 'A' && x <= 'Z')
#define IS_LOWER(x) (x >= 'a' && x <= 'z')
#define IS_ALPHA(x) (IS_LOWER(x) || IS_UPPER(x))

#define IS_VOWEL_LOWER(x) (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u')
#define IS_VOWEL_UPPER(x) (x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U')
#define IS_VOWEL(x) (IS_VOWEL_LOWER(x) || IS_VOWEL_UPPER(x))

#define IS_DIGIT(x) (x >= '0' && x <= '9')
#define IS_ALPHANUM(x) (IS_ALPHA(x) || IS_DIGIT(x))

#define IS_WHITE_SPACE(x) (x == ' ' || x == '\t' || x == '\r' || x == '\n' || x == '\0')

#define IS_SPECIAL_CHAR(x) (x >= 32 && x <= 127 && !IS_ALPHABET(x) && !IS_DIGIT(x) && !IS_WHITE_SPACE(x))

int main()
{
}