#include <stdio.h>

int main(void)
{
    char c; // To hold response
    while (1) {
        printf("MAIN MENU:\n");
        printf("l: left, r: right, q: quit -> ");
        scanf(" %c", &c);
        switch (c) {
        case 'q':
            goto end_while; // Out of "while(1)"
        case 'l':
            printf("LEFT MENU:\n");
            printf("select a or b: ");
            scanf(" %c", &c);
            switch (c) {
            case 'a':
                printf("you chose 'a'\n");
                continue; // Back to main menu
            case 'b':
                printf("you chose 'b'\n");
                continue; // Back to main menu
            default:
                printf("you didn't choose a or b!\n");
                continue; // Back to main menu
            }
            break;
        case 'r':
            printf("RIGHT MENU:\n");
            printf("select c or d: ");
            scanf(" %c", &c);
            switch (c) {
            case 'c':
                printf("you chose 'c'\n");
                continue; // Back to main menu
            case 'd':
                printf("you chose 'd'\n");
                continue; // Back to main menu
            default:
                printf("you didn't choose c or d!\n");
                continue; // Back to main menu
            }
        }

        printf("you must type l or r or q!\n");
    }

end_while:
    printf("quitting menu...\n");
}
