#include <iostream>
#include <vector>
#include <algorithm>

unsigned char checkVectorInclude(std::vector<int> vecOne, std::vector<int> vecTwo)
{
    std::sort(vecOne.begin(), vecOne.end());
    std::sort(vecTwo.begin(), vecTwo.end());

    if (vecOne == vecTwo) return '0';
    if (std::includes(vecTwo.begin(), vecTwo.end(), vecOne.begin(), vecOne.end())) return '1';
    if (std::includes(vecOne.begin(), vecOne.end(), vecTwo.begin(), vecTwo.end())) return '2';
    return '3';
}

int main()
{
    std::size_t sizeOne, sizeTwo;
    std::vector<int> vecOne, vecTwo;

    std::cin >> sizeOne;
    vecOne.resize(sizeOne);
    for (std::size_t index = 0; index < sizeOne; ++index)
        std::cin >> vecOne[index];

    std::cin >> sizeTwo;
    vecTwo.resize(sizeTwo);
    for (std::size_t index = 0; index < sizeTwo; ++index)
        std::cin >> vecTwo[index];

    std::cout << checkVectorInclude(vecOne, vecTwo) << '\n';
    return 0;
}
