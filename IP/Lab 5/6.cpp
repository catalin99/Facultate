#include <fstream>
#include <cstring>

bool delimiter(char ch)
{
    return ch == ' ' || ch == '\t';
}

int main()
{
    std::ifstream read("input.txt");

    const std::size_t MaxSize = 1000;
    char text[MaxSize] {};
    std::size_t maxLineSize = 0;

    while (read.getline(text, MaxSize)) {
        for (std::size_t index = 0; text[index]; ++index)
            while (text[index] && delimiter(text[index]) && delimiter(text[index + 1]))
                std::strcpy(text + index, text + index + 1);
        maxLineSize = std::max(maxLineSize, std::strlen(text));
    }

    read.close();
    read.clear();
    read.open("input.txt");

    std::ofstream write("output.txt");

    while (read.getline(text, MaxSize)) {
        for (std::size_t index = 0; text[index]; ++index)
            while (text[index] && delimiter(text[index]) && delimiter(text[index + 1]))
                std::strcpy(text + index, text + index + 1);

        write.width(maxLineSize + 1);
        write << std::right << text << '\n';
    }

    return 0;
}
