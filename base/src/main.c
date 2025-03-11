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
}

// 函数用于处理天数
char *processDays(int days)
{
    static char result[2];
    if (days > 0 && days <= 9)
    {
        // 如果是一位数，在前面添加空格
        sprintf(result, " %d", days);
    }
    else
    {
        // 如果是两位数，直接转换为字符串
        sprintf(result, "%d", days);
    }
    return result;
}

char *processMonths(int moved_day, int month_day)
{
    static char result[6][7];
    int day = 1;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (moved_day != 0)
            {
                sprintf(result[i][j], "  ");
                moved_day--;
            }
            else
            {
                if (day <= month_day)
                {
                    a_day_layout(day);
                    day++;
                }
            }
            printf(" ");
        }
        if (day <= month_day)
        {
            printf("\n");
        }
    }
}

int main()
{
    int testDays = 4;
    char *processed = processDays(testDays);
    printf("%s", processed);
    printf("\n");

    all_day_layout(4, 28);
    // month_layout(2, 6, 28);
    // year_layout(2025, 3);
}
