#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* use time and ctime to print the current time */
/* handle errors using fprintf and exit function */

int main()
{
    time_t rawtime = time(0);

    if (rawtime == ((time_t)-1)) {
        fprintf(stderr, "Failure to get the current time.\n");
        exit(1);
    }

    char * timerep = ctime(&rawtime);
    if (timerep == NULL) {
        fprintf(stderr, "Failure to convert the current time.\n");
        exit(1);
    }

    printf("Current time: %s \n", timerep);
    exit(0);
}
