#include <iostream>

using ui_t = unsigned int;
using ul_t = unsigned long;

bool perfect(ui_t number)
{
    ui_t sum = 0;

    if (!number) return false;

    for (ui_t divisor = 1; divisor < number; ++divisor)
        if (number % divisor == 0)
            sum += divisor;

    return sum == number;
}

ul_t perfectNumbers(ui_t number)
{
    ui_t first = 0, second = 0;

    while (!first || !second) {
        if (perfect(number)) {
            if (!first)
                first = number;
            else if (!second)
                second = number;
        }
        --number;

        if (!number) return 0;
    }

    return first + second;
}

int main()
{
    ui_t number;
    std::cin >> number;
    std::cout << perfectNumbers(number) << '\n';
    return 0;
}
