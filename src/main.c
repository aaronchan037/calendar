#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 自定义库文件
#include "data.h"
#include "info.h"

int main(int argc, char *argv[])
{
  const char *version = "v0.2";
  const char *build_date = "2022.3.14";

  // 特定参数处理
  for (int i = 0; i < argc; ++i)
  {
    if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0)
    {
      print_help(argv[0], version, build_date);
      return 0;
    }
    else if (strcmp(argv[i], "--version") == 0 || strcmp(argv[i], "-V") == 0)
    {
      print_version(argv[0], version, build_date);
      return 0;
    }
  }

  // 没有参数时打印欢迎信息
  if (argc != 2)
  {
    print_welcome(argv[0]);
    return 0;
  }

  // 生成日历
  int year = atoi(argv[1]);
  // 年份范围限制
  if (year < 1970 || year > 65535)
  {
    fprintf(stderr, "Year must be between 1970 and 65535.\n");
    return 1;
  }

  for (int i = 0; i < 4; ++i)
  {
    char a[8][21], b[8][21], c[8][21];
    generate_month_layout(year, 3 * i + 1, a);
    generate_month_layout(year, 3 * i + 2, b);
    generate_month_layout(year, 3 * i + 3, c);

    for (int j = 0; j < 8; ++j)
    {
      fwrite(a[j], 1, 21, stdout);
      putchar(' ');
      fwrite(b[j], 1, 21, stdout);
      putchar(' ');
      fwrite(c[j], 1, 21, stdout);
      putchar('\n');
    }
  }

  return 0;
}