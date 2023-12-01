#include "Day1.h"

int Day1::part1()
{
    auto &inputFile = this->readFile();
    int res = 0;
    std::string line;

    while (std::getline(inputFile, line))
    {
        res += findCalibrationValue(line);
    };
    return res;
}

int Day1::part2()
{
    std::map<std::string, int> dictionary{
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9},
    };

    auto &inputFile = this->readFile();
    int res = 0;
    std::string line;

    while (std::getline(inputFile, line))
    {
        res += findCalibrationValueWithWords(line, dictionary);
    };
    return res;
}

std::string Day1::day()
{
    return "day1";
}

int findCalibrationValue(std::string &line)
{
    size_t firstDigitPos = line.find_first_of("0123456789");
    size_t lastDigitPos = line.find_last_of("0123456789");
    if (firstDigitPos == std::string::npos || lastDigitPos == std::string::npos)
    {
        return 0;
    }
    int res = (line[firstDigitPos] - '0') * 10 + (line[lastDigitPos] - '0');
    return res;
}

int findCalibrationValueWithWords(std::string &line, std::map<std::string, int> &dictionary)
{
    size_t firstDigitPos = line.find_first_of("0123456789");
    int firstDigit = 0;
    if (firstDigitPos != std::string::npos)
    {
        firstDigit = (line[firstDigitPos] - '0') * 10;
    }
    size_t lastDigitPos = line.find_last_of("0123456789");
    int lastDigit = 0;
    if (lastDigitPos != std::string::npos)
    {
        lastDigit = (line[lastDigitPos] - '0');
    }

    size_t firstWordPos = line.length();
    std::string firstWord = "";
    size_t lastWordPos = 0;
    std::string lastWord = "";

    for (auto const& [key, val] : dictionary) {
        size_t tmp = line.find(key);
        if (tmp != std::string::npos && tmp < firstWordPos) {
            firstWordPos = tmp;
            firstWord = key;
        }
        tmp = line.rfind(key);
        if (tmp != std::string::npos && tmp > lastWordPos) {
            lastWordPos = tmp;
            lastWord = key;
        }
    }

    int firstFinal = firstDigit;
    int lastFinal = lastDigit;
    // there must be at least one digit
    if (firstWordPos != std::string::npos && firstWordPos < firstDigitPos)
    {
        firstFinal = dictionary[firstWord] * 10;
    }
    if (lastWordPos != std::string::npos && lastWordPos > lastDigitPos)
    {
        lastFinal = dictionary[lastWord];
    }
    return firstFinal + lastFinal;
}
