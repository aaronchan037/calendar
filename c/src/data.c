#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

// 获取月份的起始日期偏移
long get_month_beginning(unsigned short year, unsigned short month)
{
    // 基于儒略日来获取具体月份的第一天是星期几
    unsigned short a = (14 - month) / 12;
    unsigned short y = year + 4800 - a;
    unsigned short m = month + 12 * a - 3;
    return ((153 * m + 2) / 5) + 365 * y + (y / 4) - (y / 100) + (y / 400) - 32044;
}

// 生成月份布局
void generate_month_layout(int year, int month, char output[8][21])
{
    // 对输入的年份和月份进行有效性分析
    assert(month >= 1 && month <= 12);
    assert(year >= 1970 && year <= 65535);

    // 月份头部
    const char *head[] = {
        // 42的格子
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
        "       November       Su Mo Tu We Th Fr Sa",
        "       December       Su Mo Tu We Th Fr Sa"};
    // 日期主体
    const char *body =
        "  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31";

    // 将head数组中对应月份的字符串复制到output二维字符数组的第一行
    strcpy(output[0], head[month - 1]);

    long this_month_beg = get_month_beginning(year, month);
    long next_month_beg = get_month_beginning(year + (month == 12), month % 12 + 1);
    long month_length = next_month_beg - this_month_beg;
    long head_length = (this_month_beg + 1) % 7;
    // 42 * 3 = 126
    long tail_length = 126 - 3 * (head_length + month_length);

    memset(output[2], ' ', 3 * head_length);
    strncpy(output[2] + 3 * head_length, body, 3 * month_length);
    memset(output[2] + 3 * (head_length + month_length), ' ', tail_length);
}
