/* Excercise 5-8

   There is no error checking in day_of_year or month_day. Remedy this defect. */

#include <stdio.h>
#define BEGYEAR 0
#define ENDYEAR 3000
#define MONTHS 12
#define DAYS 365

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 21, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day) {
    int i, leap;
    leap = year%4 == 0 && year%100 != 0 || year%400 == 0;

    // Out of the date ranges
    if(year < BEGYEAR || year > ENDYEAR || month > MONTHS || day < 1 || day > (leap == 0 ? DAYS : DAYS+1)) {
        return -1;
    }

    if(daytab[leap][month] != day) {
        return -1;
    }

    for(i = 1; i < month; i++) {
        day += daytab[leap][i];
    }

    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;
    
    leap = year%4 == 0 && year%100 != 0 || year %400 == 0;

    if(year < BEGYEAR || year > ENDYEAR || yearday < 1 || yearday > (leap == 0 ? DAYS : DAYS+1)) {
        *pmonth = -1;
        *pday = -1;
        return;
    }

    for(i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}

int main() {
    printf("%d\n", day_of_year(2012, 5, 24));
    printf("%d\n", day_of_year(2012, 28, 2));

    return 0;
}
