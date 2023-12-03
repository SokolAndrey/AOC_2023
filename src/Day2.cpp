#include "Day2.h"


Game Day2::parseGame(const std::string& line)
{
    std::string COLON = ":";
    std::string SEMICOLON = ";";
    std::string WS = " ";
    std::string COMMA = ",";
    Game res;
    std::vector<std::string> game = this->splitString(line, COLON);
    
    int gameID = std::stoi(this->splitString(game[0], WS)[1]);
    res.ID = gameID;
    std::vector<std::string> gameTurns = this->splitString(game[1], SEMICOLON);
    for (const std::string& turn : gameTurns)
    {
        std::vector<std::string> colourGroups = this->splitString(turn, COMMA);
        std::map<std::string, int> gameTurn;
        for (const std::string& colourGroup : colourGroups)
        {
            std::string trimmedCG = this->trim(colourGroup);
            std::vector<std::string> tmp = this->splitString(trimmedCG, WS);
            std::string colour = tmp[1];
            std::string c = tmp[0];
            int count = 0;
            try {
                count = std::stoi(c);
            }
            catch(const std::exception& e) {
                std::cout << e.what() << std::endl;
            }
            gameTurn[colour] = count;
        }
        res.turns.push_back(gameTurn);
    }
    return res;
}

int Day2::part1()
{
    std::map<std::string, int> allCubes {
        {"red", 12},
        {"green", 13},
        {"blue", 14},
    };
    auto &inputFile = this->readFile();
    int res = 0;

    std::string line;
    while (std::getline(inputFile, line))
    {
        Game game = this->parseGame(line);
        bool isValid = true;
        int i = 0;
        for (auto& turn : game.turns)
        {
            for (auto const& [colour, count] : turn)
            {
                if (allCubes.count(colour) <= 0)
                {
                    isValid = false;
                }
                else if (allCubes[colour] < count)
                {
                    isValid = false;
                }
            }
        }
        if (isValid)
        {
            res += game.ID;
        }
    };
    return res;
}

int Day2::part2()
{

    auto &inputFile = this->readFile();
    int res = 0;

    std::string line;
    while (std::getline(inputFile, line))
    {
        Game game = this->parseGame(line);
        game.calculateMinGame();
        res += game.power();

    }
    return res;
}

std::string Day2::day()
{
    return "day2";
}
