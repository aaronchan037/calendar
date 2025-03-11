#include <stdio.h>
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
    // 输出月份
    else if (format == "month")
    {
        // 提取月份信息（struct tm 中的月份是从 0 开始计数的，所以要加 1）
        int month = local_time->tm_mon + 1;
        // 输出当前月份
        printf("%d\n", month);
    }
    // 格式错误
    else
    {
        printf("Invalid format.\n");
        return 1;
    }

    return 0;
}

int main()
{
    const char *format = "year";
    int now_date = get_now_date(format);
    if (now_date == 0)
    {
        return 1;
    }

    return 0;
}
