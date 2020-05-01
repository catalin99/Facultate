#include <iostream>
#include <vector>
#include <utility>

using ui_t = unsigned int;
using matrix = std::vector<std::pair<int, int>>;

matrix primeTwins(ui_t count, ui_t lowerBound)
{
    const ui_t TotalPrimes = 100000;
    bool primes[TotalPrimes] {};

    primes[0] = primes[1] = true;
    for (ui_t i = 2; i < TotalPrimes; ++i)
        if (!primes[i])
            for (ui_t j = i * 2; j < TotalPrimes; j += i)
                primes[j] = true;

    while (primes[++lowerBound]);
    ui_t first = lowerBound;
    while (primes[++lowerBound]);
    ui_t second = lowerBound;

    matrix result;
    result.emplace_back(first, second);
    --count;

    while (count) {
        while (primes[++lowerBound]);
        result.emplace_back(second, lowerBound);
        second = lowerBound;
        --count;
    }

    return result;
}

int main()
{
    ui_t count, lowerbound;
    std::cin >> count >> lowerbound;
    matrix result = primeTwins(count, lowerbound);
    for (const auto p : result)
        std::cout << p.first << ' ' << p.second << '\n';
    return 0;
}
