#include <iostream>

using ull_t = unsigned long long;

bool isPalindrom(ull_t number)
{
    int reversed = 0, init = number;

    while (number) {
        reversed = reversed * 10 + number % 10;
        number /= 10;
    }

    return reversed == init;
}

int main()
{
    ull_t number;
    std::cin >> number;
    std::cout << std::boolalpha << isPalindrom(number) << '\n';
    return 0;
}
