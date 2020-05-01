#include <iostream>
#include <algorithm>

const std::size_t MaxSize = 100;

using ui_t = unsigned int;

struct vector
{
    int cells[MaxSize];
    std::size_t size;

    void read() {
        std::cin >> size;
        for (std::size_t index = 0; index < size; ++index)
            std::cin >> cells[index];
    }

    void print() const {
        for (std::size_t index = 0; index < size; ++index)
            std::cout << cells[index] << ' ';
        std::cout << '\n';
    }
};

bool isPartOfFibonnaci(vector vec, ui_t startingNumber)
{
    std::sort(vec.cells, vec.cells + vec.size);

    ui_t fibs[] = {0, 1, 1};

    while (fibs[2] < startingNumber) {
        fibs[0] = fibs[1];
        fibs[1] = fibs[2];
        fibs[2] = fibs[1] + fibs[0];
    }

    for (std::size_t index = 0; index < vec.size; ++index) {
        if (vec.cells[index] != fibs[2])
            return false;

        fibs[0] = fibs[1];
        fibs[1] = fibs[2];
        fibs[2] = fibs[1] + fibs[0];
    }

    return true;
}

int main()
{
    vector vec;
    vec.read();

    ui_t startingNumber;
    std::cin >> startingNumber;

    std::cout << std::boolalpha << isPartOfFibonnaci(vec, startingNumber);
    return 0;
}
