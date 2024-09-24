//
// Created by wolek on 20.09.24.
//

#include "OutputBuilder.hpp"
#include <cctype>

std::vector<std::pair<int, int>> OutputBuilder::getFirstAndLastNumber(std::vector<std::string> &tokens) {
  std::vector<std::pair<int, int>> numbers;
  for(auto token : tokens)
  {
    std::pair<int,int> digits;
    for(auto it = token.begin(); it != token.end(); it++)
    {
      if (std::isdigit(*it))
      {
        digits.first = *it - '0';
        break;
      }
    }
    for(auto it = token.rbegin(); it != token.rend(); it++)
    {
      if(std::isdigit(*it))
      {
        digits.second = *it - '0';
        break;
      }
    }
    numbers.push_back(digits);
  }
  return numbers;
}