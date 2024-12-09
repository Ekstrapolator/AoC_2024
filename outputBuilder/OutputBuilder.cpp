//
// Created by wolek on 20.09.24.
//


#include <cctype>
#include <cassert>
#include <algorithm>
#include <numeric>

#include "OutputBuilder.hpp"
#include "fmt/format.h"
#include <regex>
#include <set>

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

size_t OutputBuilder::getDay01_part01(std::vector<std::string> &tokens) {
  std::vector<size_t> leftList;
  std::vector<size_t> rightList;

  for (auto &token : tokens) {
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

  for (auto i{0}; i < leftList.size(); i++) {
    if (leftList.at(i) < rightList.at(i)) {
      distance.push_back(rightList.at(i) - leftList.at(i));
    } else {
      distance.push_back(leftList.at(i) - rightList.at(i));
    }

  }

  return std::accumulate(distance.begin(), distance.end(), static_cast<size_t>(0));
}

size_t OutputBuilder::getDay01_part02(std::vector<std::string> &tokens) {
  std::vector<size_t> leftList;
  std::vector<size_t> rightList;

  for (auto &token : tokens) {
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
    leftList.push_back(std::stoll(snumberOne));
    rightList.push_back(std::stoll(snumberTwo));
  }

  assert(leftList.size() == rightList.size() && "List must have same size");
  size_t resoult{0};
  for (auto num : leftList) {
    size_t count = std::count(rightList.begin(), rightList.end(), num);
    resoult += count * num;
  }
  return resoult;
}

safeRaports OutputBuilder::getDay02_part01(std::vector<std::string> &tokens) {
  safeRaports count{0};
  for (auto tok : tokens) {
    std::string num;
    std::vector<int> raport;
    for (const auto &c : tok) {
      if (c == ' ') {
        raport.push_back(std::stoi(num));
        num.clear();
      } else {
        num.push_back(c);
      }
    }
    if (!num.empty())
    {
    raport.push_back(std::stoi(num));
    }
    if (isRaportSafe(raport)) {
      count++;
    } else {
      fmt::print("Unsafe raport\n");
    }
  }
  return count;
}

void printVec(const std::vector<int> & elemets) {
  for (auto elem : elemets) {
    fmt::print("{} ", elem);
  }
}

size_t OutputBuilder::getDay03_part01(std::vector<std::string> &tokens) {
  //mul(158,758)
  std::vector<std::pair<int,int>> mul;
  std::regex getNum(R"(\d+)");
  for (auto token : tokens) {
    std::sregex_iterator it(token.begin(),token.end(), getNum);
    mul.emplace_back(std::stoi(it->str()), std::stoi(it++->str()));
  }
  size_t res{0};
  for (auto m : mul)
  {
    res += m.first * m.second;
  }
  return res;
}

bool isValidChar(const char in, const int pos)
{
  if (const std::string reference{"XMAS"}; in != reference.at(pos))
  {
  return false;
  }
  return true;
}

std::set<Directions> getValidDir(Point point, size_t rowMax, size_t colMax) {
  constexpr int len{3};
  std::set<Directions> validDir;
  bool canMoveDown = point.row + len <= rowMax;
  bool canMoveUp = point.row - len >= 0;
  bool canMoveRight = point.col + len <= colMax;
  bool canMoveLeft = point.col - len >= 0;

  if (canMoveDown) validDir.insert(Directions::down);
  if (canMoveUp) validDir.insert(Directions::up);
  if (canMoveRight) validDir.insert(Directions::right);
  if (canMoveLeft) validDir.insert(Directions::left);

  if (canMoveUp && canMoveRight) validDir.insert(Directions::upRight);
  if (canMoveUp && canMoveLeft) validDir.insert(Directions::upLeft);
  if (canMoveDown && canMoveRight) validDir.insert(Directions::downRight);
  if (canMoveDown && canMoveLeft) validDir.insert(Directions::downLeft);

return validDir;
}

size_t OutputBuilder::getDay04_part01(std::vector<std::string> &tokens) {
  auto rowsMax = tokens.size();
  auto columnsMax = tokens.at(0).size();

  for(auto row{0}; row < rowsMax; row++)
  {
    for(auto column{0}; column < columnsMax; column++)
    {
      if(tokens.at(row).at(column) == 'X')
      {
        std::set<Directions> directions = getValidDir({row,column},rowsMax, columnsMax);
        if(!directions.empty())
        {
          for (auto dir : directions)
          {
            switch (dir) {

              case up:
                break;
              case upRight:break;
              case right:break;
              case downRight:break;
              case down:break;
              case downLeft:break;
              case left:break;
              case upLeft:break;
            }
          }
        }
      }
    }
  }
  fmt::print("Char at 6,0 {}\n", tokens.at(6).at(1));
  fmt::print("row {} col {}\n", rowsMax, columnsMax);

  return 0xff;
}

bool OutputBuilder::isRaportSafe(std::vector<int> &inRaport) {
  std::vector<int> ascendig = inRaport;
  std::vector<int> descndig = inRaport;
  std::sort(ascendig.begin(), ascendig.end(), std::less<>());
  std::sort(descndig.begin(), descndig.end(), std::greater<>());
  if (ascendig != inRaport and descndig != inRaport) {
    return false;
  }

  if (ascendig == inRaport) {
  std::vector<int> distance;
    for (size_t i{1}; i < inRaport.size(); i++) {
    // 2-1 > 3 or 5 <= 3
      if (inRaport.at(i) - inRaport.at(i - 1) > 3 or inRaport.at(i) <= inRaport.at(i - 1)) {
        return false;
      }
      distance.push_back(inRaport.at(i) - inRaport.at(i - 1));
    }
    fmt::print("A report safe\t");
    printVec(distance);
    fmt::print("\n");
    return true;
  } else {
    // descending by 1 or 2
    std::vector<int> distance;
    for (size_t i{1}; i < inRaport.size(); i++) {
      if (inRaport.at(i - 1) - inRaport.at(i) > 3 or inRaport.at(i) >= inRaport.at(i - 1)) {
        return false;
      }
      distance.push_back(inRaport.at(i - 1) - inRaport.at(i));
    }
    fmt::print("D report safe\t");
    printVec(distance);
    fmt::print("\n");
    return true;
  }
}
