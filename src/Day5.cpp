#include "Day5.h"

Range::Range(const Range &other)
{
    this->source = other.source;
    this->destination = other.destination;
    this->count = other.count;
}

Range::Range(long source, long destination, long count)
{
    this->source = source;
    this->destination = destination;
    this->count = count;
}

Range& Range::operator=(const Range &other)
{
    this->source = other.source;
    this->destination = other.destination;
    this->count = other.count;
    return *this;
}

bool Range::isWithin(long s)
{
    return this->source <= s && s < (this->source + count);
}

long Range::translate(long s)
{
    return (s - source) + destination;
}

WeirdMap::WeirdMap(const WeirdMap& other)
{
    this->ranges = other.ranges;
}

void WeirdMap::addRange(Range& range)
{
    this->ranges.push_back(range);
}

long WeirdMap::translate(long source)
{
    for (auto& range : this->ranges)
    {
        if (range.isWithin(source)) {
            return range.translate(source);
        }
    }
    // if didn't find the corresponding range just map one-to-one
    return source;
}

long Almanac::translate(long number, std::string source, std::string destination)
{
    std::string tmp = source;
    long res = number;
    while (tmp != destination) {
        if (linkingMap.find(source) == linkingMap.end()) {
            return -42;
        }
        tmp = linkingMap[tmp];
        if (data.find(tmp) == data.end()) {
            return -23;
        }
        WeirdMap wp = data[tmp];
        res = wp.translate(res);
    }
    return res;
}

int Day5::part1()
{
    auto& inputFile = this->readFile();
    std::string line;
    std::vector<long> seeds;
    std::map<std::string, std::string> mapLinking;
    std::map<std::string, WeirdMap> data; 
    std::string currentMapName;
    WeirdMap currentMap;
    while (std::getline(inputFile, line))
    {
        if (line.rfind("seeds:") == 0) {
            auto rawSeeds = this->splitString(this->trim(this->splitString(line, ":")[1]), " ");
            for (auto const& i : rawSeeds)
            {
                if (!this->trim(i).empty() && isdigit(i[0])) {
                    seeds.push_back(std::stol(i));
                }
            }
        } else if (line.rfind("map:") != std::string::npos) {
            auto mapName = this->splitString(this->trim(this->splitString(line, " ")[0]), "-");
            mapLinking[mapName[0]] = mapName[2];
            currentMapName = mapName[2];
        } else if (this->trim(line).empty()) {
            data[currentMapName] = currentMap;
            currentMap = WeirdMap();
        } else {
            auto rawRange = this->splitString(this->trim(line), " ");
            long source = std::stol(this->trim(rawRange[1]));
            long destination = std::stol(this->trim(rawRange[0]));
            long count = std::stol(this->trim(rawRange[2]));
            Range r = Range(source, destination, count);
            currentMap.addRange(r);
        }
    }
    if (data.find(currentMapName) == data.end()) {
        data[currentMapName] = currentMap; 
    }
    Almanac a = Almanac();
    a.setData(data);
    a.setLinkingMap(mapLinking);
    long res = LONG_MAX;
    for (auto const& s : seeds)
    {
        long tmp = a.translate(s, "seed", "location");
        if (tmp < res) {
            res = tmp;
        }
    }
    std::cout << "Result: " << res << std::endl;
    return -1;
}

int Day5::part2()
{
    return -1;
}

std::string Day5::day()
{
    return "day5";
}
