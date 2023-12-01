#include "Solver.h"


std::string Solver::day()
{
    return "";
}

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
