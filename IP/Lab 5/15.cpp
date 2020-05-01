#include <iostream>

bool palindrom(long number)
{
    long reversed = 0;

    for (long auxiliary = number; auxiliary; auxiliary >>= 1)
        reversed = (auxiliary & 1) | (reversed << 1);

    return reversed == number;
}

int main()
{
    long number;
    std::cin >> number;
    std::cout << std::boolalpha << palindrom(number) << '\n';
    return 0;
}
