#include <stdbool.h>

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
