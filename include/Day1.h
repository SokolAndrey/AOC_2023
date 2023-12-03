#pragma once
#include "Solver.h"

class Day1 : public Solver
{

public:
    int part1() override;
    int part2() override;
    std::string day() override;
};

int findCalibrationValue(std::string& line);
int findCalibrationValueWithWords(std::string& line, std::map<std::string, int>& dictionary);
