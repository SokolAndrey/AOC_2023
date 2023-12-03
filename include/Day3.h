#pragma once
#include "Solver.h"

struct Coordinate
{
    int x, y;

    Coordinate() : x(0), y(0) {}
    Coordinate(int x, int y) : x(x), y(y) {}
    Coordinate(const Coordinate &other) : x(other.x), y(other.y) {}

    std::set<Coordinate> neighbours();

    bool operator<(const Coordinate& that) const
    {
        if (x == that.x)
        {
            return y < that.y;
        }
        return x < that.x;
    }

    bool operator==(const Coordinate& that) const
    {
        return x == that.x && y == that.y;
    }
};

enum ElementType
{
    NUMBER,
    SYMBOL,
    EMPTY
};

std::string typeToString(ElementType t);


struct GridElement
{
    ElementType type;
    std::set<Coordinate> coordinates;
    int value;
    std::string symbol;

    GridElement() : type(EMPTY), value(-1), symbol("") {}
    GridElement(ElementType type, int value, const std::set<Coordinate> &coordinates) : type(type), value(value), symbol(""), coordinates(coordinates) {}
    GridElement(ElementType type, std::string symbol, const std::set<Coordinate> &coordinates) : type(type), value(-1), symbol(symbol), coordinates(coordinates) {}
    GridElement(const GridElement &other) : type(other.type), value(other.value), symbol(other.symbol), coordinates(other.coordinates) {}

    std::set<Coordinate> neighbours();
};

class Day3 : public Solver
{
public:
    int part1() override;
    int part2() override;
    std::string day() override;
};
