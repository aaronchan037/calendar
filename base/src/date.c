#include <stdio.h>

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