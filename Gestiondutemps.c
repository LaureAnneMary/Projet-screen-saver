#include <stdio.h>
#include <time.h>

int main(void)
{
    time_t secondes;
    struct tm instant;

    time(&secondes);
    instant=*localtime(&secondes);

    printf("%d:%d:%d\n", instant.tm_hour, instant.tm_min, instant.tm_sec);
    int horloge[3];
    horloge[0] = instant.tm_hour;
    horloge[1] = instant.tm_min;
    horloge[2] = instant.tm_sec;
    printf("%d\n", horloge[0]);
    printf("%d\n", horloge[1]);
    printf("%d\n", horloge[2]);
    return 0;
}
