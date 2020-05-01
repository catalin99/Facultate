#include <iostream>

using uc_t = unsigned char;
using ull_t = unsigned long long;

uc_t sumBinaryFigure(ull_t number)
{
    uc_t sum = 0;

    while (number) {
        sum += number % 2;
        number >>= 1;
    }

    return sum;
}

int main()
{
    ull_t number;
    std::cin >> number;
    std::cout << static_cast<ull_t>(sumBinaryFigure(number)) << '\n';
    return 0;
}
