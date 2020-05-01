#include <iostream>

const std::size_t MaxSize = 100;

struct vector
{
    int cells[MaxSize];
    std::size_t size;

    void print() const {
        for (std::size_t index = 0; index < size; ++index)
            std::cout << cells[index] << ' ';
        std::cout << '\n';
    }
};

struct matrix
{
    vector vectors[MaxSize];
    std::size_t rows, columns;

    void print() const {
        for (std::size_t row = 0; row < rows; ++row) {
            for (std::size_t col = 0; col < columns; ++col)
                std::cout << vectors[row].cells[col] << ' ';
            std::cout << '\n';
        }
    }
};

bool checkIsIn(vector vec, matrix mat)
{
    if (vec.size == mat.rows)
        for (std::size_t row = 0; row < mat.rows; ++row) {
            bool found = true;
            for (std::size_t index = 0; index < vec.size; ++index)
                if (vec.cells[index] != mat.vectors[row].cells[index])
                    found = false;
            if (found) return found;
        }

    if (vec.size == mat.columns)
        for (std::size_t col = 0; col < mat.columns; ++col) {
            bool found = true;
            for (std::size_t index = 0; index < vec.size; ++index)
                if (vec.cells[index] != mat.vectors[index].cells[col])
                    found = false;
            if (found) return found;
        }

    return false;
}

int main()
{
    vector vec;
    matrix mat;

    std::cin >> vec.size;
    for (std::size_t index = 0; index < vec.size; ++index)
        std::cin >> vec.cells[index];

    std::cin >> mat.rows >> mat.columns;
    for (std::size_t row = 0; row < mat.rows; ++row)
        for (std::size_t col = 0; col < mat.columns; ++col)
            std::cin >> mat.vectors[row].cells[col];

    std::cout << '\n';
    vec.print();
    std::cout << '\n';
    mat.print();
    std::cout << '\n';

    std::cout << std::boolalpha << checkIsIn(vec, mat) << '\n';
    return 0;
}
