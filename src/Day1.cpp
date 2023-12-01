#include "Day1.h"

int Day1::part1()
{
    auto& inputFile = this->readFile();
    int res = 0;
    std::string line;

    while(std::getline(inputFile, line))
    {
        res += findCalibrationValue(line);
    };
    return res;
}

int Day1::part2()
{
    return 42;
}

std::string Day1::day()
{
    return "day1";
}

int findCalibrationValue(std::string& line)
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
