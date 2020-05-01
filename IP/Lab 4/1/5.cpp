#include <iostream>

using us_t = unsigned short;

us_t dayOfTheWeek(us_t year, us_t month, us_t day)
{
    if (month < 3)
        --year;
    else
        day += year - 2;

    int dayOfTheW = (23 * month / 9 + day + 4 + year / 4 - year / 100 + year / 400) % 7;
    return !dayOfTheW ? 7 : dayOfTheW;
}

int main()
{
    us_t year, month, day;
    std::cin >> year >> month >> day;
    std::cout << dayOfTheWeek(year, month, day) << '\n';
    return 0;
}
