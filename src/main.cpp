#include <iostream>
#include "Day1.h"
#include "Day2.h"
#include "Day3.h"
#include "Day4.h"
#include "Day5.h"

int main(int argc, char* argv[]) {
    if (argc != 2)
    {
        std::cerr << "Usage: " << argv[0] << " <puzzle day>" << std::endl;
        return -1;
    }

    int day = std::atoi(argv[1]);

    Solver* solver = nullptr;
    switch (day)
    {
        case 1:
        solver = new Day1();
        break;
        case 2:
        solver = new Day2();
        break;
        case 3:
        solver = new Day3();
        break;
        case 4:
        solver = new Day4();
        break;
        case 5:
        solver = new Day5();
        break;
        default:
        std::cerr << "There is no implementation for day " << day << " yet" << std::endl;
        return -1;
    }
    int part1 = solver->part1();
    std::cout<<"Answer for part 1:" << std::endl << part1 << std::endl;
    int part2 = solver->part2();
    std::cout<<"Answer for part 2:" << std::endl << part2 << std::endl;
    return 0;
}
