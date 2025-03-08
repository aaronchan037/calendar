#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "date.h"

// 判断是否为闰年
int isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
    {
        return true;
        // true -> 1
    }
    else
    {
        return false;
        // false -> 0
    }
}

void gen_month_layout()
{
    const char *month_name[] = {
        "      January       ",
        "      February      ",
        "       March        ",
        "       April        ",
        "        May         ",
        "       June         ",
        "       July         ",
        "      August        ",
        "     September      ",
        "      October       ",
        "      November      ",
        "      December      "};
    const char *week[] = {"Su Mo Tu We Th Fr Sa"};
}

void a_day(int day_number, char output[1][2])
{
    int arr[1][2];
    for (int i = 0; i < 2; i++)
    {
        for (int day = 1; day <= day_number; i++)
        {
        }
    }
}

// 天数布局
void day_layout(char output[6][20])
{
    int arr[6][20];
    int value = 0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            arr[i][j] = (" %d", value);
            value++;
        }
    }

    for (int i = 1; i <= 9; i++)
    {
        printf(" ");
        printf("%d", i);
        printf(" ");
    }
    for (int i = 10; i <= 31; i++)
    {
        printf("%d", i);
        printf(" ");
    }
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

int main()
{
    // bool istrue = true;
    // printf("%d\n", istrue);
    // bool isfalse = false;
    // printf("%d\n", isfalse);

    // printf("%s\n", argv[1]);
    // printf("%d\n", year);
    // printf("%d\n", isLeapYear(year));

    // char a[6][20];
    // day_layout(a);

    // a_day_layout(28);
    // a_day_layout(4);

    for (int i = 1; i <= 31; i++)
    {
        a_day_layout(i);
        printf(" ");
    }

    return 0;
}
