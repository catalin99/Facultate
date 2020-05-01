#include <iostream>

using ui_t = unsigned int;
using us_t = unsigned short;

bool isPrime(ui_t number)
{
    if (number <= 1) return false;
    if (number == 2 || number == 3) return true;

    for (ui_t divisor = 2; divisor * divisor <= number; ++divisor)
        if (number % divisor == 0)
            return false;

    return true;
}

us_t primeCount(ui_t number)
{
    us_t primeDiv = 0;

    while (number > 1)
        for (ui_t divisor = 2; divisor <= number; ++divisor)
            if (number % divisor == 0) {
                ++primeDiv;
                while (number % divisor == 0)
                    number /= divisor;
            }

    return primeDiv;
}

us_t primeDivisors(ui_t left, ui_t right)
{
    us_t maxDivs = 0;
    for (ui_t number = left; number <= right; ++number) {
        const us_t primes = primeCount(number);
        if (primes > maxDivs)
            maxDivs = primes;
    }

    us_t totalDivs = 0;
    for (ui_t number = left; number <= right; ++number)
        if (primeCount(number) == maxDivs)
            ++totalDivs;

    return totalDivs;
}

int main()
{
    ui_t left, right;
    std::cin >> left >> right;
    std::cout << primeDivisors(left, right) << '\n';
    return 0;
}
