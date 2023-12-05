#include "Day4.h"


int Day4::part1()
{
    auto& inputFile = this->readFile();
    std::string line;
    int res = 0;
    while (std::getline(inputFile, line))
    {
        std::vector<std::string> card = this->splitString(line, ":");
        std::string cardID = card[0];
        std::vector<std::string> cardNumbers = this->splitString(card[1], "|");
        std::vector winningNumberStrings = this->splitString(this->trim(cardNumbers[0]), " ");
        std::vector playerNumberStrings = this->splitString(this->trim(cardNumbers[1]), " ");
        std::set<int> wn, pn;
        for (auto const& i : winningNumberStrings) {
            if (i.empty()) {
                continue;
            }
            int number = std::stoi(this->trim(i));
            wn.insert(number);
        }
        for (auto const& i : playerNumberStrings) {
            if (i.empty()) {
                continue;
            }
            int number = std::stoi(this->trim(i));
            pn.insert(number);
        }
        std::vector<int> intersection(pn.size());
        std::vector<int>::iterator it;
        it = std::set_intersection(wn.begin(), wn.end(), pn.begin(), pn.end(), intersection.begin());
        intersection.resize(it - intersection.begin());
        int points = intersection.size() > 0 ? std::pow(2, intersection.size() - 1) : 0;
        res += points;
    }
    return res;
}

int Day4::part2()
{
    auto& inputFile = this->readFile();
    std::string line;
    int res = 0;
    std::map<int, int> tmpResult;
    int i = 0;
    while (std::getline(inputFile, line))
    {
        std::vector<std::string> card = this->splitString(line, ":");
        std::string cardID = card[0];
        std::vector<std::string> cardNumbers = this->splitString(card[1], "|");
        std::vector winningNumberStrings = this->splitString(this->trim(cardNumbers[0]), " ");
        std::vector playerNumberStrings = this->splitString(this->trim(cardNumbers[1]), " ");
        std::set<int> wn, pn;
        for (auto const& i : winningNumberStrings) {
            if (i.empty()) {
                continue;
            }
            int number = std::stoi(this->trim(i));
            wn.insert(number);
        }
        for (auto const& i : playerNumberStrings) {
            if (i.empty()) {
                continue;
            }
            int number = std::stoi(this->trim(i));
            pn.insert(number);
        }
        std::vector<int> intersection(pn.size());
        std::vector<int>::iterator it;
        it = std::set_intersection(wn.begin(), wn.end(), pn.begin(), pn.end(), intersection.begin());
        intersection.resize(it - intersection.begin());
        int matches = intersection.size();
        tmpResult[++i] = matches;
    }
    std::map<int, int>::reverse_iterator rit;
    std::map<int, int> resMap;
    for (rit = tmpResult.rbegin(); rit != tmpResult.rend(); rit++) {
        int curVal = rit->second;
        if (curVal == 0) {
            resMap[rit->first] = 0;
        } else {
            for (int i = 0; i < curVal; i++) {
                resMap[rit->first] += resMap[rit->first + i + 1] + 1; 
            }
        }
    }
    for (auto const& [k, v] : resMap) {
        res += v + 1;
    }
    return res;
}

std::string Day4::day()
{
    return "day4";
}