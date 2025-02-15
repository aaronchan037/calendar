#include <stdio.h>

// 判断是否为闰年
int isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// 计算指定年份1月1日是星期几
int getStartDayOfYear(int year)
{
    int totalDays = 0;
    for (int i = 1900; i < year; i++)
    {
        if (isLeapYear(i))
        {
            totalDays += 366;
        }
        else
        {
            totalDays += 365;
        }
    }
    return (totalDays + 1) % 7;
}

// 计算指定月份的天数
int getDaysInMonth(int year, int month)
{
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear(year) && month == 2)
    {
        return 29;
    }
    return days[month - 1];
}

// 显示指定年份和月份的日历
void displayCalendar(int year, int month)
{
    int startDay = getStartDayOfYear(year);
    for (int i = 1; i < month; i++)
    {
        startDay += getDaysInMonth(year, i);
    }
    startDay %= 7;

    printf("     %d年%d月\n", year, month);
    printf(" 日 一 二 三 四 五 六\n");

    for (int i = 0; i < startDay; i++)
    {
        printf("   ");
    }

    int days = getDaysInMonth(year, month);
    for (int i = 1; i <= days; i++)
    {
        printf("%3d", i);
        if ((startDay + i) % 7 == 0)
        {
            printf("\n");
        }
    }
    printf("\n");
}

int main()
{
    int year, month;
    printf("请输入年份: ");
    scanf("%d", &year);
    printf("请输入月份: ");
    scanf("%d", &month);

    if (year < 1900 || month < 1 || month > 12)
    {
        printf("输入的年份或月份不合法。\n");
    }
    else
    {
        displayCalendar(year, month);
    }

    return 0;
}
