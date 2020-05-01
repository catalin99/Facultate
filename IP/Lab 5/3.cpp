#include <iostream>
#include <string>
#include <map>

struct Group
{
    Group(int number) : number(number) {}
    virtual ~Group() {}

    std::string basicTranslation() const
    {
        static const std::string toDigit[] { "", "unu", "doua", "trei", "patru", "cinci", "sase", "sapte", "opt", "noua" };
        static std::map<int, std::string> toTens {{10, "zece"}, {11, "unsprezece"}, {14, "paisprezece"}, {16, "saisprezece"}, {60, "saizeci"}};

        std::string result;
        int number = this->number;

        if (number >= 100) {
            if (number / 100 == 1)
                result += "o suta ";
            else
                result += toDigit[number / 100] + " sute ";
            number = number / 10 % 10 * 10 + number % 10;
        }

        if (number >= 10) {
            if (toTens.find(number) != toTens.end())
                result += toTens[number];
            else if (number < 20)
                result += toDigit[number % 10] + "sprezece";
            else if (number % 10 == 0)
                result += toDigit[number / 10] + "zeci";
            else if (number / 10 == 6)
                result += "saizeci si " + toDigit[number % 10];
            else
                result += toDigit[number / 10] + "zeci si " + toDigit[number % 10];
            return result + " ";
        }

        if (number >= 0)
            return result + toDigit[number];
    }

    virtual std::string translate() const = 0;

    protected:
        int number;
};

struct Thousands : public Group
{
    Thousands(int number) : Group(number) { }

    std::string translate() const override
    {
        const std::string result = basicTranslation();

        if (!number) return result;
        if (number == 1) return "o mie ";

        const int tens = number / 10 % 10 * 10 + number % 10;

        if (0 < tens && tens < 20) return result + " mii ";
        return result + "de mii ";
    }
};

struct Millions : public Group
{
    Millions(int number) : Group(number) { }

    std::string translate() const override
    {
        const std::string result = basicTranslation();

        if (!number) return result;
        if (number == 1) return "un milion ";

        const int tens = number / 10 % 10 * 10 + number % 10;

        if (0 < tens && tens < 20) return result + " milioane ";
        return result + "de milioane ";
    }
};

struct Units : public Group
{
    Units(int number) : Group(number) { }

    std::string translate() const override { return basicTranslation().empty() ? "zero" : basicTranslation(); }
};

std::string toRomanian(std::string number)
{
    number.insert(number.begin(), 9 - number.size(), '0');

    Group* millions = new Millions(std::stoi(number.substr(0, 3)));
    Group* thousands = new Thousands(std::stoi(number.substr(3, 3)));
    Group* units = new Units(std::stoi(number.substr(6, 3)));

    const std::string result = millions->translate() + thousands->translate() + units->translate();

    delete millions;
    delete thousands;
    delete units;

    return result;
}

int main()
{
    std::string number;
    std::cin >> number;
    std::cout << toRomanian(number) << '\n';
    return 0;
}
