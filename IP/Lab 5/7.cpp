#include <iostream>

using Piece = char[4];

enum Index { Color, Type, Row, Column };

bool attacks(const Piece source, const Piece target)
{
    if (source[Color] == target[Color])
        return false;

    if (source[Type] == 'p') {
        if (source[Color] == 'w')
            return (source[Row] - 1 == target[Row] && source[Column] - 1 == target[Column]) ||
                   (source[Row] - 1 == target[Row] && source[Column] + 1 == target[Column]);
        else
            return (source[Row] + 1 == target[Row] && source[Column] - 1 == target[Column]) ||
                   (source[Row] + 1 == target[Row] && source[Column] + 1 == target[Column]);
    }

    if (source[Type] == 'r')
        return source[Row] == target[Row] || source[Column] == target[Column];

    if (source[Type] == 'h') {
        const int directionx[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
        const int directiony[] = { 1, 2, 2, 1, -1, -2, -2, -1 };

        for (std::size_t index = 0; index < 8; ++index)
            if (source[Row] + directionx[index] == target[Row] && source[Column] + directiony[index] == target[Column])
                return true;
        return false;
    }

    if (source[Type] == 'b')
        return std::abs(source[Row] - target[Row]) == std::abs(source[Column] - target[Column]);

    if (source[Type] == 'q')
        return (source[Row] == target[Row] || source[Column] == target[Column]) ||
                std::abs(source[Row] - target[Row]) == std::abs(source[Column] - target[Column]);

    const int directionx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    const int directiony[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

    for (std::size_t index = 0; index < 8; ++index)
        if (source[Row] + directionx[index] == target[Row] && source[Column] + directiony[index] == target[Column])
            return true;
    return false;
}

int main()
{
    Piece first, second;

    // exemplu: wp04 <-> pion alb pe prima linie si a cincea coloana
    std::cin >> first >> second;
    std::cout << attacks(first, second);
    return 0;
}
