#include <stdio.h>
#include <assert.h>

#include "date.h"

// 一天的布局
void a_day_layout(int day)
{
    if (day <= 9)
    {
        printf(" %d", day);
    }
    else
    // day > 10
    {
        printf("%d", day);
    }
}

// 一个月中的天数布局
void all_day_layout(int moved_day, int month_day)
{
    assert(moved_day >= 0 && moved_day <= 6);
    int arr[6][7];
    int day = 1;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (moved_day != 0)
            {
                printf("  ");
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

// 第一行信息：月份
void month_header(int month)
{
    switch (month)
    {
    case 1:
        printf("      January       ");
        break;
    case 2:
        printf("      February      ");
        break;
    case 3:
        printf("       March        ");
        break;
    case 4:
        printf("       April        ");
        break;
    case 5:
        printf("        May         ");
        break;
    case 6:
        printf("       June         ");
        break;
    case 7:
        printf("       July         ");
        break;
    case 8:
        printf("      August        ");
        break;
    case 9:
        printf("     September      ");
        break;
    case 10:
        printf("      October       ");
        break;
    case 11:
        printf("      November      ");
        break;
    case 12:
        printf("      December      ");
        break;
    }
    printf("\n");
}

// 一个月的布局
void month_layout(int month, int moved_day, int month_day)
{
    // 第一行的信息：月份名称
    month_header(month);
    // 第二行的信息：星期
    const char week[] = {"Su Mo Tu We Th Fr Sa"};
    printf("%s\n", week);
    all_day_layout(moved_day, month_day);
}

// 二月份特殊处理
void second_month(int moved_day, int second_month_day)
{
    // 第一行的信息：月份名称
    month_header(2);
    // 第二行的信息：星期
    const char week[] = {"Su Mo Tu We Th Fr Sa"};
    printf("%s\n", week);
    all_day_layout(moved_day, second_month_day);
}

// 二月份的天数
int Fe_day(int year)
{
    if (isLeapYear(year))
    {
        return 29;
    }
    else
    {
        return 28;
    }
}
