#include "Solver.h"

std::ifstream& Solver::readFile()
{
    std::string path = "../data/";
    path.append(this->day());
    path.append("/input.txt");
    std::ifstream* inputFile = new std::ifstream(path);
    if (!inputFile->is_open())
    {
        delete inputFile;
        throw std::runtime_error("Error opening file");
    }
    return *inputFile;
}

std::vector<std::string> Solver::splitString(const std::string& input, const std::string& delimiter)
{
    std::vector<std::string> result;
    size_t start = 0;
    size_t end = input.find(delimiter);

    while (end != std::string::npos) {
        result.push_back(input.substr(start, end - start));
        start = end + delimiter.length();
        end = input.find(delimiter, start);
    }

    result.push_back(input.substr(start));

    return result;
}

std::string Solver::trim(const std::string& str)
{
    size_t start = 0;
    while (start < str.length() && std::isspace(str[start]))
    {
        start++;
    }
    size_t end = str.length();
    while (end > start && std::isspace(str[end - 1]))
    {
        end--;
    }
    return str.substr(start, end -start);
}
