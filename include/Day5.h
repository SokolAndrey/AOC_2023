#ifndef DAY5
#define DAY5
#include "Solver.h"

/*
In order to work with std::vector a class must meet the following requirements:
 - It must meet the requirements of CopyAssignable and CopyConstructible.
 - It must meet the requirements of Erasable, although many member functions impose stricter requirements.
*/
class Range
{
public:
    Range() {}
    Range(long source, long destination, long count);
    Range(const Range &other);
    Range &operator=(const Range &other);
    ~Range() {}
    bool isWithin(long source);
    long translate(long source);

private:
    long source, destination, count;
};

class WeirdMap
{
public:
    WeirdMap() {}
    WeirdMap(const WeirdMap &other);
    long translate(long source);
    void addRange(Range &range);

private:
    std::vector<Range> ranges;
};

class Almanac
{
public:
    long translate(long number, std::string source, std::string destination);
    void setLinkingMap(std::map<std::string, std::string> linkingMap) { this->linkingMap = linkingMap; };
    void setData(std::map<std::string, WeirdMap> data) { this->data = data; };

private:
    std::map<std::string, std::string> linkingMap;
    std::map<std::string, WeirdMap> data;
};

class Day5 : public Solver
{
public:
    int part1() override;
    int part2() override;
    std::string day() override;
};
#endif // DAY5