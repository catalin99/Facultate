#include <iostream>
#include <iomanip>

using us_t = unsigned short;

bool isLeapYear(us_t year)
{
    if (year % 4) return false;
    if (year % 100) return true;
    if (year % 400) return false;
    return true;
}

int main()
{
    us_t year;
    std::cin >> year;
    std::cout << std::boolalpha << isLeapYear(year) << '\n';
    return 0;
}
