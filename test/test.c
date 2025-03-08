#include <stdio.h>

long get_month_beginning(unsigned short year, unsigned short month)
{
    // 基于儒略日来获取具体月份的第一天是星期几
    unsigned short a = (14 - month) / 12;
    unsigned short y = year + 4800 - a;
    unsigned short m = month + 12 * a - 3;
    return ((153 * m + 2) / 5) + 365 * y + (y / 4) - (y / 100) + (y / 400) - 32044;
}

int main(int argc, char *argv[])
{
    long day = get_month_beginning(*argv[1], *argv[2]);
    printf("%d\n", day);
}