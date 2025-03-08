#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "month.h"
#include "date.h"

void gen_month_layout()
{
}

int other(int argc, char *argv[])
{
    int year = atoi(argv[1]);
    if (isLeapYear(year))
    {
        printf("Leap Year\n");
    }
    else
    {
        printf("Not leap year\n");
    }
}

// 一年的布局
void year_layout(int year, int year_moved_day)
{
    int arr[4][3];
    int month_day[12] = {31, Fe_day(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int moved_day = year_moved_day;
    int month = 1;
    // 输出
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (month == 2)
            {
                second_month(moved_day, Fe_day(year));
            }
            else
            {
                month_layout(month, moved_day, month_day[month - 1]);
            }
            moved_day = ((moved_day + month_day[month - 1]) % 7);

            if (month <= 12)
            {
                month++;
            }
            printf(" ");
        }
        printf("\n");
    }

    // printf("%d\n", year);
}

int main()
{
    // printf("%s\n", argv[1]);
    // printf("%d\n", year);
    // printf("%d\n", isLeapYear(year));

    // char a[6][20];
    // day_layout(a);

    // month_layout(2, 6, 28);
    year_layout(2025, 3);

    return 0;
}
