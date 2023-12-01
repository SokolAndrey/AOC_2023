#pragma once

#include <iostream>
#include <fstream>
#include <stdexcept>


class Solver
{
    public:
        std::ifstream& readFile();
        virtual std::string day();
        virtual int part1() = 0;
        virtual int part2() = 0;
};