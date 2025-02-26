#include <stdio.h>

// 打印欢迎信息
void print_welcome(const char *program_name)
{
    printf("Calendar Generator\n");
    printf("====================================\n");
    printf("Welcome to %s, we are glad to have you here!\n", program_name);
    printf("\n");
    printf("This program generates a calendar for the specified year.\n");
    printf("\n");
    printf("Type '%s --help' for more information.\n", program_name);
}

// 打印帮助信息
void print_help(const char *program_name, const char *version, const char *build_date)
{
    printf("Calendar Generator %s (%s build)\n", version, build_date);
    printf("====================================\n");
    printf("Usage:\n");
    printf("  %s [OPTIONS] <COMMAND>\n", program_name);
    printf("Options:\n");
    printf("  --output, -o   \t\t Output a calendar for the specified\n");
    printf("      <default>  \t\t default output a calendar for this year\n");
    printf("        year     \t\t for a year\n");
    printf("        month    \t\t for a month\n");
    printf("  --help, -h     \t\t Print this help documentation\n");
    printf("  --version, -V  \t\t Print the version\n");
    printf("Commands:\n");
    printf("  <year>         \t\t Generate a calendar for the specified year\n");
    printf("  <year>-<month> \t\t Generate a calendar for the specified month\n");
    printf("Example: %s 2022\n", program_name);
    printf("Help:\n");
    printf("  - The year should be an integer between 1970 and 65535.\n");
}

// 打印版本信息
void print_version(const char *program_name, const char *version, const char *build_date)
{
    printf("%s version: %s (%s build)\n", program_name, version, build_date);
}
