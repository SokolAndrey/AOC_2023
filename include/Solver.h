#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>
#include <set>
#include <map>
#include <tuple>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>



class Solver
{
    public:
        std::ifstream& readFile();
        std::vector<std::string> splitString(const std::string& input, const std::string& delimiter);
        std::string trim(const std::string& str);
        // todo: read the file name and use it to read the input
        virtual std::string day() = 0;
        virtual int part1() = 0;
        virtual int part2() = 0;
};
