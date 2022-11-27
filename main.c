#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//the week starts with sunday so
//0 - sunday
//1- monday etc...
int main(int argc, char **argv) {
    if (argc != 2)return 69;
    char *date = argv[1];
    long day = strtol(strtok(date, "-"), NULL, 10);
    long month = strtol(strtok(NULL, "-"), NULL, 10);
    long year = strtol(strtok(NULL, "-"), NULL, 10);
    if (day > 31 || day < 1) {
        printf("Day number must be between 1 and 31 inclusive! Your input: %ld", day);
        return -1;
    }
    if (month > 12 || month < 1) {
        printf("Month number must be between 1 and 12 inclusive! Your input: %ld", month);
        return -1;
    }
    if (year < 1) {
        printf("Year number must be positive number Your input: %ld", year);
        return -1;
    }
    year -= month < 3;
    long weekday   = (day += month < 3 ? year-- : year - 2, 23*month/9 + day + 4 + year/4- year/100 + year/400)%7;

    printf("The day of the week is %ld", weekday);

    return 0;
}
