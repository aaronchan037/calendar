#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

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

// 一天为一个1×2的二维数组
void a_day_layout(int day, int output[1][2])
{
    int arr[1][2];
    if (day <= 9)
    {
        arr[1][2] = (" %d", day);
    }
    else
    // day > 10
    {
        arr[1][2] = ("%d", day);
    }
    printf("%s", arr[1][2]);
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

int main(int argc, char *argv[])
{
    // bool istrue = true;
    // printf("%d\n", istrue);
    // bool isfalse = false;
    // printf("%d\n", isfalse);

    int year = atoi(argv[1]);
    // printf("%s\n", argv[1]);
    // printf("%d\n", year);
    // printf("%d\n", isLeapYear(year));
    if (isLeapYear(year))
    {
        printf("Leap Year\n");
    }
    else
    {
        printf("Not leap year\n");
    }

    // char a[6][20];
    // day_layout(a);
    int a[1][2], b[1][2];
    a_day_layout(28, a[1][2]);
    a_day_layout(4, b[1][2]);
}
