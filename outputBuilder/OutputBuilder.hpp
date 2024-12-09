//
// Created by wolek on 20.09.24.
//

#pragma once
#include <vector>
#include <string>

typedef size_t safeRaports;

enum Directions {
  up = 0,
  upRight = 1,
  right = 3,
  downRight = 3,
  down = 4,
  downLeft = 5,
  left = 6,
  upLeft = 7,
};

struct Point
{
  int row;
  int col;
};

class OutputBuilder {
 public:
  OutputBuilder() = default;
  std::vector<std::pair<int, int>> getFirstAndLastNumber(std::vector<std::string> &tokens);
  size_t getDay01_part01(std::vector<std::string> &tokens);
  size_t getDay01_part02(std::vector<std::string> &tokens);
  safeRaports getDay02_part01(std::vector<std::string> &tokens);
  size_t getDay03_part01(std::vector<std::string> &tokens);
  size_t getDay04_part01(std::vector<std::string> &tokens);



 private:
 bool isRaportSafe(std::vector<int>& inRaport);

};


