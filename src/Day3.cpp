#include "Day3.h"

std::ostream &operator<<(std::ostream &os, const Coordinate &c)
{
    os << "(" << c.x << "," << c.y << ")";
    return os;
}

std::ostream &operator<<(std::ostream &os, const GridElement &c)
{
    std::string v = "";
    if (c.type == SYMBOL)
    {
        v = c.symbol;
    }
    else
    {
        v = std::to_string(c.value);
    }
    os << "Value: " << v << std::endl
       << "Type: " << typeToString(c.type) << std::endl
       << "Coordinates: [";
    for (Coordinate item : c.coordinates)
    {
        os << item << ", ";
    }
    os << "]" << std::endl;
    return os;
}

std::string typeToString(ElementType t)
{
    switch (t)
    {
    case NUMBER:
        return "NUMBER";
    case SYMBOL:
        return "SYMBOL";
    default:
        return "UNDEFINED";
    }
}

void readLine(const std::string &line, std::vector<GridElement>& elements, int y)
{
    std::string currentNumber;
    for (int x = 0; x < line.length(); x++)
    {
        char currentChar = line[x];
        if (std::isdigit(currentChar))
        {
            currentNumber += currentChar;
        }
        else
        {
            if (currentNumber.length() > 0)
            {
                int tmp = std::stoi(currentNumber);
                std::set<Coordinate> currentNumberCoordinates;
                for (int i = 0; i < currentNumber.length(); i++)
                {
                    currentNumberCoordinates.insert(Coordinate(x - i - 1, y));
                }
                GridElement ge = GridElement(NUMBER, tmp, currentNumberCoordinates);
                elements.push_back(ge);
                currentNumber.clear();
            }
            if (currentChar != '.' && currentChar && '\n' && currentChar != ' ' && currentChar != '\r')
            {
                Coordinate c = {x, y};
                GridElement s = GridElement(SYMBOL, std::string(1, currentChar), std::set<Coordinate>{{x, y}});
                elements.push_back(s);
            }
        }
    }
    if (currentNumber.length() > 0)
    {
        int tmp = std::stoi(currentNumber);
        std::set<Coordinate> currentNumberCoordinates;
        for (int i = 0; i < currentNumber.length(); i++)
        {
            currentNumberCoordinates.insert(Coordinate(line.length() - i - 1, y));
        }
        GridElement ge = GridElement(NUMBER, tmp, currentNumberCoordinates);
        elements.push_back(ge);
        currentNumber.clear();
    }
}

int Day3::part1()
{
    auto &inputFile = this->readFile();
    int res = 0;
    // line number
    int y = 0;
    std::string line;
    std::vector<GridElement> gridElements;
    while (std::getline(inputFile, line))
    {
        readLine(line, gridElements, y);
        ++y;
    }
    std::set<Coordinate> connected;
    for (auto &elem : gridElements)
    {
        if (elem.type == SYMBOL)
        {
            if (!elem.coordinates.empty())
            {
                Coordinate c = *elem.coordinates.begin();
                connected.insert(c);
            }
        }
    }
    
    int notIncluded = 0;
    for (auto &elem : gridElements)
    {
        if (elem.type == NUMBER)
        {
            std::set<Coordinate> en = elem.neighbours();
            bool found = false;
            for (Coordinate c : en)
            {
                for (Coordinate cc : connected)
                {
                    if (c == cc)
                    {
                        found = true;
                    }
                }
            }
            if (found)
            {
                res += elem.value;
            }
            else
            {
                notIncluded++;
            }
        }
    }

    return res;
}

int Day3::part2()
{
    auto &inputFile = this->readFile();
    int res = 0;
    // line number
    int y = 0;
    std::string line;
    std::vector<GridElement> gridElements;
    while (std::getline(inputFile, line))
    {
        readLine(line, gridElements, y);
        ++y;
    }
    std::set<Coordinate> gearCoordinates;
    for (const auto& elem : gridElements)
    {
        if (elem.symbol == "*")
        {
            if (!elem.coordinates.empty())
            {
                Coordinate c = *elem.coordinates.begin();
                gearCoordinates.insert(c);
            }
        }
    }
    for (const auto& gc : gearCoordinates)
    {
        int adj = 0;
        std::vector<GridElement> adjElems;
        for (auto& elem : gridElements)
        {
            if (elem.type == NUMBER)
            {
                for (const Coordinate ec : elem.neighbours()) {
                    if (ec == gc)
                    {
                        adj++;
                        adjElems.push_back(elem);
                    }
                }
            }
        }
        if (adj == 2) 
        {
            res += adjElems[0].value * adjElems[1].value;
        }
    }
    return res;
}

std::string Day3::day()
{
    return "day3";
}

std::set<Coordinate> Coordinate::neighbours()
{
    std::set<Coordinate> res = {
        // left
        {x - 1, y},
        // right
        {x + 1, y},
        // top
        {x, y - 1},
        // bottom
        {x, y + 1},
        // top-left
        {x - 1, y - 1},
        // bottom-left
        {x - 1, y + 1},
        // bottom-right
        {x + 1, y + 1},
        // bottom-left
        {x + 1, y - 1},
    };
    return res;
}

std::set<Coordinate> GridElement::neighbours()
{
    std::set<Coordinate> res;
    for (Coordinate c : coordinates)
    {
        std::set<Coordinate> cNeighbours = c.neighbours();
        for (Coordinate n : cNeighbours)
        {
            auto it = coordinates.find(n);
            if (it == coordinates.end())
            {
                res.insert(n);
            }
        }
    }
    return res;
}
