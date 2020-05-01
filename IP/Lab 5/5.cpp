#include <iostream>

bool delimiter(char ch)
{
    return !std::isalnum(ch) && !(ch == '-');
}

int main()
{
    const std::size_t MaxSize = 1000;
    char text[MaxSize] {};
    int result = 0;

    std::cin.get(text, MaxSize);
    for (std::size_t index = 0; text[index]; ++index)
        if (delimiter(text[index]) != delimiter(text[index + 1]))
            ++result;

    std::cout << (result + 1) / 2 << '\n';
    return 0;
}
