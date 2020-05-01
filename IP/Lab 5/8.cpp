#include <iostream>

const std::size_t MaxSize = 10001;

using ll_t = long long;
using ull_t = unsigned long long;

ull_t setOperations(ll_t sets[], char operations[], std::size_t totalNumbers)
{
    ull_t result = sets[0];

    for (std::size_t index = 1; index < totalNumbers; ++index) {
        switch (operations[index - 1]) {
            case 'U': result |= sets[index]; break;
            case 'A': result &= sets[index]; break;
            case '\\': result = (result ^ sets[index]) & result; break;
            case '/': result = (result ^ sets[index]) & sets[index]; break;
            default: break;
        }
    }

    return result;
}

int main()
{
    ll_t sets[MaxSize] {};
    char operations[MaxSize] {};

    std::size_t totalNumbers;
    std::cin >> totalNumbers;

    for (std::size_t index = 0; index < totalNumbers; ++index)
        std::cin >> sets[index];
    std::cin >> operations;

    std::cout << setOperations(sets, operations, totalNumbers) << '\n';
    return 0;
}
