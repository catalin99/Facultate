#include <iostream>
#include <string>
#include <map>

std::string translate(int number)
{
    static std::map<int, std::string> converter {
        {0, "zero"}, {1, "un"}, {2, "deux"}, {3, "trois"},
        {4, "quatre"}, {5, "cinq"}, {6, "six"}, {7, "sept"},
        {8, "huit"}, {9, "neuf"},
        {10, "dix"}, {11, "onze"}, {12, "douze"}, {13, "treize"},
        {14, "quatorze"}, {15, "quinze"}, {16, "seize"}, {17, "dix-sept"},
        {18, "dix-huit"}, {19, "dix-neuf"}
    };

    static std::map<int, std::string> tens {
        {2, "vingt"}, {3, "trente"}, {4, "quarante"}, {5, "cinquante"},
        {6, "soixante"}, {7, "soixante"}, {8, "quatre-vingt"}, {9, "quatre-vingt"}
    };

    std::string result;

    if (number >= 100) {
        if (number / 100 == 1) {
            result += "cent ";
            number %= 100;
        }
        else {
            result += converter[number / 100] + " cent";
            number %= 100;
            if (!number) result += "s";
            result += " ";
        }

        if (number % 100 == 0) return result;
    }

    if (number >= 80) {
        if (number % 80 == 0) return result + tens[number / 10] + "s";
        return result + tens[number / 10] + "-" + converter[number - 80];
    }

    if (number >= 60) {
        if (number % 60 == 0) return result + tens[number / 10];
        if (number % 10 == 1) return result + tens[number / 10] + " et " + converter[number - 60];
        return result + tens[number / 10] + "-" + converter[number - 60];
    }

    if (number >= 20) {
        if (number % 10 == 0) return result + tens[number / 10];
        if (number % 10 == 1) return result + tens[number / 10] + " et un";
        return result + tens[number / 10] + "-" + converter[number % 10];
    }

    if (number >= 0) return result + converter[number];
}

std::string toFrench(std::string number)
{
    number.insert(number.begin(), 6 - number.size(), '0');

    std::string thousands = translate(std::stoi(number.substr(0, 3)));
    std::string units = translate(std::stoi(number.substr(3, 3)));

    if (thousands == "zero")
        thousands = "";
    else {
        if (units == "zero")
            units = "";
        if (thousands == "un")
            thousands = "mille ";
        else
            thousands += " mille ";
    }

    return thousands + units;
}

int main()
{
    std::string number;
    std::cin >> number;
    std::cout << toFrench(number) << '\n';
    return 0;
}
