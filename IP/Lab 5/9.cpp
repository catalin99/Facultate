#include <iostream>
#include <vector>

bool areOrderedFibonnaci(const std::vector<int>& fibs)
{
    std::vector<int> cfibs {0, 1, 1};

    for (std::size_t index = 0; index < std::min(cfibs.size(), fibs.size()); ++index)
        if (fibs[index] != cfibs[index])
            return false;

    for (std::size_t index = 3; index < fibs.size(); ++index) {
        cfibs[0] = cfibs[1];
        cfibs[1] = cfibs[2];
        cfibs[2] = cfibs[1] + cfibs[0];

        if (fibs[index] != cfibs[2])
            return false;
    }

    return true;
}

int main()
{
    std::size_t totalNumbers;
    std::cin >> totalNumbers;

    std::vector<int> fibs(totalNumbers);
    for (std::size_t index = 0; index < totalNumbers; ++index)
        std::cin >> fibs[index];

    std::cout << areOrderedFibonnaci(fibs) << '\n';
    return 0;
}
