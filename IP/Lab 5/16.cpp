#include <iostream>

const std::size_t MaxSize = 100;

struct matrix
{
    int cells[MaxSize][MaxSize];
    std::size_t rows, columns;

    void read() {
        std::cin >> rows >> columns;
        for (std::size_t row = 0; row < rows; ++row)
            for (std::size_t col = 0; col < columns; ++col)
                std::cin >> cells[row][col];
    }

    void print() const {
        for (std::size_t row = 0; row < rows; ++row) {
            for (std::size_t col = 0; col < columns; ++col)
                std::cout << cells[row][col] << ' ';
            std::cout << '\n';
        }
    }
};

void advance(int fibs[])
{
    fibs[0] = fibs[1];
    fibs[1] = fibs[2];
    fibs[2] = fibs[1] + fibs[0];
}

bool fibonnaciSpirale(matrix mat)
{
    int fibs[] = {0, 1, 0};

    const std::size_t maxLevel = std::min(mat.rows / 2 - !(mat.rows % 2), mat.columns / 2 - !(mat.columns % 2));

    for (std::size_t level = 0; level <= maxLevel; ++level) {
        for (std::size_t index = level; index < mat.columns - level; ++index) {
            if (mat.cells[level][index] != fibs[2])
                return false;
            advance(fibs);
        }

        for (std::size_t index = level + 1; index < mat.rows - level; ++index) {
            if (mat.cells[index][mat.columns - level - 1] != fibs[2])
                return false;
            advance(fibs);
        }

        for (int index = mat.columns - level - 2; index >= static_cast<int>(level); --index) {
            if (mat.cells[mat.rows - level - 1][index] != fibs[2])
                return false;
            advance(fibs);
        }

        for (int index = mat.rows - level - 2; index >= static_cast<int>(level) + 1; --index) {
            if (mat.cells[index][level] != fibs[2])
                return false;
            advance(fibs);
        }
    }

    return true;
}

int main()
{
    matrix mat;
    mat.read();
    mat.print();
    std::cout << std::boolalpha << fibonnaciSpirale(mat) << '\n';
    return 0;
}
