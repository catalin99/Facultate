#include <iostream>

using ui_t = unsigned int;

ui_t fibonnaci_it(int index)
{
    ui_t f0 = 0, f1 = 1, f2 = f0 + f1;

    if (!index) return 0;

    for (int i = 3; i <= index; ++i) {
        f0 = f1;
        f1 = f2;
        f2 = f1 + f0;
    }

    return f2;
}

int main()
{
    int index;
    std::cin >> index;
    std::cout << fibonnaci_it(index) << '\n';
    return 0;
}
