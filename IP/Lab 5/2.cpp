#include <fstream>
#include <cstring>

const std::size_t MaxSize = 10000;
const std::size_t TotalTokens = 6;

int main()
{
    char input[MaxSize] {};
    char tokens[TotalTokens][5] { "<b>", "</b>", "<i>", "</i>", "<u>", "</u>" };

    std::ifstream read("input.txt");
    std::ofstream write("output.txt");

    while (read.getline(input, MaxSize)) {
        for (std::size_t index = 0; index < TotalTokens; ++index) {
            char* position = input;
            while ((position = std::strstr(position, tokens[index])) != nullptr) {
                char auxiliary[MaxSize] {};
                std::strcpy(auxiliary, position + std::strlen(tokens[index]));
                std::strcpy(position, auxiliary);
            }
        }

        write << input << '\n';
    }

    return 0;
}
