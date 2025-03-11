#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdint>
#include <cstdlib>

#include "info.hpp"

inline long get_month_beginning(uint16_t year, uint16_t month)
{
  // Get the first day of a month
  uint16_t a = static_cast<uint16_t>((14 - month) / 12);
  uint16_t y = static_cast<uint16_t>(year + 4800 - a);
  uint16_t m = static_cast<uint16_t>(month + 12 * a - 3);
  return ((153 * m + 2) / 5) + 365 * y + (y / 4) - (y / 100) + (y / 400) - 32044;
}

struct MonthLayout
{
  MonthLayout(int year, int month)
  {
    assert(month >= 1 && month <= 12);
    assert(year >= 1970 && year <= 65535);
    memcpy(output[0], head[month - 1], 42);

    long this_month_beg{get_month_beginning(year, month)},
        next_month_beg{get_month_beginning(year + (month == 12), month % 12 + 1)};
    long month_length = next_month_beg - this_month_beg;
    long head_length = (this_month_beg + 1) % 7; // assuming positive
    long tail_length = 126 - 3 * (head_length + month_length);

    std::fill_n(output[2], 3 * head_length, ' ');
    memcpy(output[2] + 3 * head_length, body, 3 * month_length);
    std::fill_n(output[2] + 3 * (head_length + month_length), tail_length, ' ');
  }
  char output[8][21];
  static constexpr const char *body =
      "  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31";
  static constexpr const char *head[] = {
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
      "      December        Su Mo Tu We Th Fr Sa",
  };
};

int main(int argc, char *argv[])
{
  // 检查特定的参数
  for (int i = 1; i < argc; ++i)
  {
    if (std::string(argv[i]) == "--help" || std::string(argv[i]) == "-h")
    {
      printHelp(argv[0]);
      return 0;
    }
    else if (std::string(argv[i]) == "--version" || std::string(argv[i]) == "-V")
    {
      printVersion(argv[0]);
      return 0;
    }
  }

  // 如果没有传参，那就返回以下内容
  if (argc != 2)
  {
    printHelp(argv[0]);
    return 0;
  }

  int year = std::atoi(argv[1]);
  if (year < 1970 || year > 65535)
  {
    // std::cerr是输出错误消息的
    std::cerr << "Year must be between 1970 and 65535." << std::endl;
    return 1;
  }

  for (int i = 0; i < 4; ++i)
  {
    MonthLayout a{year, 3 * i + 1}, b{year, 3 * i + 2}, c{year, 3 * i + 3};
    for (int j = 0; j < 8; ++j)
    {
      fwrite(a.output[j], 1, 21, stdout);
      putc(' ', stdout);
      fwrite(b.output[j], 1, 21, stdout);
      putc(' ', stdout);
      fwrite(c.output[j], 1, 21, stdout);
      putc('\n', stdout);
    }
  }
  return 0;
}
