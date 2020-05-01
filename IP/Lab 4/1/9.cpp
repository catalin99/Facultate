#include <iostream>

int main()
{
    const std::size_t MaxNumbers = 10000;
    int numberCount, sum = 0, numbers[MaxNumbers] {};

    std::cin >> numberCount;
    for (int index = 0; index < numberCount; ++index) {
        std::cin >> numbers[index];
        if (numbers[index] < 0)
            sum += numbers[index];
    }

    std::cout << sum << '\n';
    return 0;
}
