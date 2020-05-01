#include <iostream>

const std::size_t MaxSize = 100;

using ui_t = unsigned int;

struct matrix
{
    int cells[MaxSize][MaxSize];
    std::size_t size;

    void read() {
        std::cin >> size;
        for (std::size_t row = 0; row < size; ++row)
            for (std::size_t col = 0; col < size; ++col)
                std::cin >> cells[row][col];
    }

    void print() const {
        for (std::size_t row = 0; row < size; ++row) {
            for (std::size_t col = 0; col < size; ++col)
                std::cout << cells[row][col] << ' ';
            std::cout << '\n';
        }
    }
};

matrix rotate(matrix mat, ui_t rotLeft, ui_t rotRight)
{
    matrix result = mat;

    for (; rotLeft; --rotLeft) {
        for (std::size_t row = 0; row < mat.size; ++row)
            for (std::size_t col = 0; col < mat.size; ++col)
                result.cells[mat.size - col - 1][row] = mat.cells[row][col];
        mat = result;
    }

    for (; rotRight; --rotRight) {
        for (std::size_t row = 0; row < mat.size; ++row)
            for (std::size_t col = 0; col < mat.size; ++col)
                result.cells[col][mat.size - row - 1] = mat.cells[row][col];
        mat = result;
    }

    return result;
}

int main()
{
    matrix mat;
    mat.read();

    ui_t rotLeft, rotRight;
    std::cin >> rotLeft >> rotRight;

    std::cout << "Before: \n";
    mat.print();
    mat = rotate(mat, rotLeft, rotRight);
    std::cout << "After: \n";
    mat.print();
    return 0;
}
