#include <iostream>

// Print the help documentation
void printHelp(const char *programName)
{
    std::cout << "Usage: " << programName << " <year>" << std::endl;
    std::cout << "Help:" << std::endl;
    std::cout << "  - This program generates a calendar for the specified year." << std::endl;
    std::cout << "  - The year should be an integer between 1970 and 65535." << std::endl;
    std::cout << "Version: v0.1 (2022.3.14 build)" << std::endl;
}

// Print the version
void printVersion(const char *programName)
{
    std::cout << programName << " Version: v0.1 (2022.3.14 build)" << std::endl;
}