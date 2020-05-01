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

void transformMatrix(matrix& mat)
{
    int zeros[MaxSize * MaxSize][2] {};
    std::size_t totalZeros = 0;

    for (std::size_t row = 0; row < mat.rows; ++row)
        for (std::size_t col = 0; col < mat.columns; ++col)
            if (!mat.cells[row][col]) {
                zeros[totalZeros][0] = row;
                zeros[totalZeros][1] = col;
                ++totalZeros;
            }

    for (std::size_t index = 0; index < totalZeros; ++index) {
        for (std::size_t row = 0; row < mat.rows; ++row)
            mat.cells[row][zeros[index][1]] = 0;

        for (std::size_t col = 0; col < mat.columns; ++col)
            mat.cells[zeros[index][0]][col] = 0;
    }
}

int main()
{
    matrix mat;
    mat.read();

    std::cout << "Before: \n";
    mat.print();
    transformMatrix(mat);
    std::cout << "After: \n";
    mat.print();
    return 0;
}
