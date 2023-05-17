#include <setjmp.h>
#include <stdio.h>

jmp_buf buf;

void error_recovery()
{
    printf("Error 108.\n");
    longjmp(buf, 108);
}

int main()
{
    while (1) {
        if (setjmp(buf))
            break;
        else
            error_recovery();
    }
}