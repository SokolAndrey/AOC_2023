#pragma once
#include "Solver.h"


struct Game {
    int ID;
    std::vector<std::map<std::string, int>> turns;
    std::map<std::string, int> minGame;

    void calculateMinGame()
    {
        minGame = {
            {"green", 1},
            {"blue", 1},
            {"red", 1},
            };
        for (auto const& turn : turns)
        {
            for (auto const& [colour, count] : turn)
            {
                if (minGame[colour] < count)
                {
                    minGame[colour] = count;
                }
            }
        }
    }

    int power()
    {
        int res = 1;
        for (auto const& [_, count] : minGame)
        {
            res *= count;
        }
        return res;
    }
};

class Day2 : public Solver
{

public:
    int part1() override;
    int part2() override;
    std::string day() override;
    Game parseGame(const std::string& line);
};
