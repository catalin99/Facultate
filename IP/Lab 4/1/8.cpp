#include <iostream>
#include <string>
#include <numeric>

int digitControlISBN(std::string isbn)
{
    auto digitAdder = [] (int init, char ch) { return init + (std::isdigit(ch) ? ch - '0' : 0); };

    int sum = 0;

    do {
        sum = std::accumulate(std::begin(isbn), std::end(isbn), 0, digitAdder);
        isbn = std::to_string(sum);
    } while (sum > 9);

    return sum;
}

int main()
{
    // exemplu ISBN: 85-254-1293-7
    std::string isbn;
    std::cin >> isbn;
    std::cout << digitControlISBN(isbn) << '\n';
    return 0;
}
