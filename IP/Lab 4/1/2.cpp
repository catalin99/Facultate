#include <iostream>

using ui_t = unsigned int;

ui_t fibonnaci_rec(int index)
{
    if (index <= 1) return index;
    return fibonnaci_rec(index - 1) + fibonnaci_rec(index - 2);
}

int main()
{
    int index;
    std::cin >> index;
    std::cout << fibonnaci_rec(index) << '\n';
    return 0;
}
