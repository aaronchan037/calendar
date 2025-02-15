#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

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
  const char *body = "  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31";

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

void print_help(const char *program_name)
{
  printf("Usage: %s <year>\n", program_name);
  printf("Help:\n");
  printf("  - This program generates a calendar for the specified year.\n");
  printf("  - The year should be an integer between 1970 and 65535.\n");
  printf("Version: v0.1 (2022.3.14 build)\n");
}

void print_version(const char *program_name)
{
  printf("%s Version: v0.1 (2022.3.14 build)\n", program_name);
}

int main(int argc, char *argv[])
{
  for (int i = 0; i < argc; ++i)
  {
    if (strcmp(argv[i], "--help") == 0 || strcmp(argv[i], "-h") == 0)
    {
      print_help(argv[0]);
      return 0;
    }
    else if (strcmp(argv[i], "--version") == 0 || strcmp(argv[i], "-V") == 0)
    {
      print_version(argv[0]);
      return 0;
    }
  }

  if (argc != 2)
  {
    print_help(argv[0]);
    return 0;
  }

  int year = atoi(argv[1]);
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