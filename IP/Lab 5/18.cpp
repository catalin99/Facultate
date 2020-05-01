#include <iostream>
#include <limits>
#include <cmath>
#include <iomanip>

const std::size_t MaxSize = 10000;

int main()
{
    double numbers[MaxSize] {};
    int totalNumbers;

    std::cin >> totalNumbers;
    for (int index = 0; index < totalNumbers; ++index) {
        std::cin >> numbers[index];
        if (std::abs(numbers[index]) - std::abs(std::floor(numbers[index])) < std::numeric_limits<double>::epsilon()) {
            --index;
            --totalNumbers;
        }
    }

    for (int index = 0; index < totalNumbers; ++index)
        std::cout << std::setprecision(std::numeric_limits<long double>::digits10 + 1) << numbers[index] << ' ';
    return 0;
}
