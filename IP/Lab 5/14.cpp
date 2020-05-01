#include <iostream>

using ul_t = unsigned long;
using ui_t = unsigned int;

const std::size_t MaxSize = 1000;

ul_t bitOperations(long numbers[], char operations[], ui_t x)
{
    ul_t result = numbers[0];

    for (ui_t index = 1; index < x; ++index) {
        switch (operations[index - 1]) {
            case '|': result |= numbers[index]; break;
            case '&': result &= numbers[index]; break;
            case '^': result ^= numbers[index]; break;
            case '>': result >>= numbers[index]; break;
            case '<': result <<= numbers[index]; break;
            case '~': result = ~result; break;
            default: break;
        }
    }

    return result;
}

int main()
{
    long numbers[MaxSize] {};
    char operations[MaxSize] {};
    ui_t totalNumbers;

    std::cin >> totalNumbers;
    for (ui_t index = 0; index < totalNumbers; ++index)
        std::cin >> numbers[index];
    std::cin >> operations;

    std::cout << bitOperations(numbers, operations, totalNumbers);
    return 0;
}
