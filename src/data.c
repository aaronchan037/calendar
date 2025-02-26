#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

// 获取当前年份或月份
int get_now_date(const char *format)
{
    // 用于存储当前时间的秒数
    time_t current_time;
    // 用于存储转换后的本地时间信息
    struct tm *local_time;
    // 获取当前时间（从1970年1月1日00:00:00 UTC以来的秒数）
    current_time = time(NULL);
    if (current_time == ((time_t)-1))
    {
        fprintf(stderr, "Failed to obtain current time.\n");
        return 1;
    }
    // 将当前时间转换为本地时间
    local_time = localtime(&current_time);
    if (local_time == NULL)
    {
        fprintf(stderr, "Failed to convert to local time.\n");
        return 1;
    }

    // 判断格式
    // 输出年份
    if (format == "year")
    {
        // 提取年份信息（struct tm 中的年份是从 1900 开始计数的，所以要加 1900）
        int year = local_time->tm_year + 1900;
        // 输出当前年份
        printf("%d\n", year);
    }
    else if (format == "month")
    {
        // 提取月份信息（struct tm 中的月份是从 0 开始计数的，所以要加 1）
        int month = local_time->tm_mon + 1;
        // 输出当前月份
        printf("%d\n", month);
    }
    else
    {
        printf("Invalid format.\n");
        return 1;
    }

    return 0;
}

// 获取月份的起始日期偏移
long get_month_beginning(unsigned short year, unsigned short month)
{
    unsigned short a = (14 - month) / 12;
    unsigned short y = year + 4800 - a;
    unsigned short m = month + 12 * a - 3;
    return ((153 * m + 2) / 5) + 365 * y + (y / 4) - (y / 100) + (y / 400) - 32044;
}

// 生成月份布局
void generate_month_layout(int year, int month, char output[8][21])
{
    assert(month >= 1 && month <= 12);
    assert(year >= 1970 && year <= 65535);

    // 月份头部
    const char *head[] = {
        "       January        Su Mo Tu We Th Fr Sa",
        "      February        Su Mo Tu We Th Fr Sa",
        "        March         Su Mo Tu We Th Fr Sa",
        "        April         Su Mo Tu We Th Fr Sa",
        "         May          Su Mo Tu We Th Fr Sa",
        "        June          Su Mo Tu We Th Fr Sa",
        "        July          Su Mo Tu We Th Fr Sa",
        "       August         Su Mo Tu We Th Fr Sa",
        "      September       Su Mo Tu We Th Fr Sa",
        "       October        Su Mo Tu We Th Fr Sa",
        "      November        Su Mo Tu We Th Fr Sa",
        "      December        Su Mo Tu We Th Fr Sa"};
    // 日期主体
    const char *body =
        "  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31";

    strcpy(output[0], head[month - 1]);

    long this_month_beg = get_month_beginning(year, month);
    long next_month_beg = get_month_beginning(year + (month == 12), month % 12 + 1);
    long month_length = next_month_beg - this_month_beg;
    long head_length = (this_month_beg + 1) % 7;
    long tail_length = 126 - 3 * (head_length + month_length);

    memset(output[2], ' ', 3 * head_length);
    strncpy(output[2] + 3 * head_length, body, 3 * month_length);
    memset(output[2] + 3 * (head_length + month_length), ' ', tail_length);
}
