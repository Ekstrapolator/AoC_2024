//
// Created by wolek on 20.09.24.
//

#include "OutputBuilder.hpp"
#include <cctype>
#include <set>
#include <cassert>
#include <algorithm>
#include <numeric>


std::vector<std::pair<int, int>> OutputBuilder::getFirstAndLastNumber(std::vector<std::string> &tokens) {
  std::vector<std::pair<int, int>> numbers;
  for (auto token : tokens) {
    std::pair<int, int> digits;
    for (auto it = token.begin(); it != token.end(); it++) {
      if (std::isdigit(*it)) {
        digits.first = *it - '0';
        break;
      }
    }
    for (auto it = token.rbegin(); it != token.rend(); it++) {
      if (std::isdigit(*it)) {
        digits.second = *it - '0';
        break;
      }
    }
    numbers.push_back(digits);
  }
  return numbers;
}

size_t OutputBuilder::getDay01(std::vector<std::string> &tokens) {
  std::vector<size_t> leftList;
  std::vector<size_t> rightList;

  for (auto& token : tokens) {
    std::string snumberOne;
    std::string snumberTwo;
    bool firstNumber{true};
    for (auto character : token) {
      if (firstNumber) {
        if (character != ' ') {
          snumberOne.push_back(character);
        } else {
          firstNumber = false;
        }
      } else {
        if (character != ' ') {
          snumberTwo.push_back(character);
        }
      }
    }
    size_t numberOne = std::stoll(snumberOne);
    size_t numberTwo = std::stoll(snumberTwo);
    leftList.push_back(numberOne);
    rightList.push_back(numberTwo);
  }

  std::vector<size_t> distance;
  std::sort(leftList.begin(), leftList.end());
  std::sort(rightList.begin(), rightList.end());

  assert(leftList.size() == rightList.size() && "List must have same size");

  for(auto i{0}; i < leftList.size(); i++)
  {
    if(leftList.at(i) < rightList.at(i))
    {
      distance.push_back(rightList.at(i) - leftList.at(i));
    }
    else{
      distance.push_back(leftList.at(i) - rightList.at(i));
    }


  }

  return std::accumulate(distance.begin(), distance.end(),static_cast<size_t>(0));
}
