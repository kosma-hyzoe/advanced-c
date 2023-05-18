#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t rawtime = time(0);

    struct tm befofmonth;
    befofmonth = *localtime(&rawtime);
    befofmonth.tm_hour = 0;
    befofmonth.tm_min = 0;
    befofmonth.tm_sec = 0;
    befofmonth.tm_mday = 1;

    double secs_this_month = difftime(rawtime, mktime(&befofmonth));

    printf("Seconds passed since the beginning of month: %.f\n", secs_this_month);
    return 0;
}
