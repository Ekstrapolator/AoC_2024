//
// Created by wolek on 20.09.24.
//

#pragma once
#include <vector>
#include <string>

#include "Tokenizer.hpp"
#include "InputManager.hpp"
#include "2Dutils.hpp"

typedef size_t safeRaports;

class OutputBuilder {
 public:
  OutputBuilder() = default;
  std::vector<std::pair<int, int>> getFirstAndLastNumber(std::vector<std::string> &tokens);
  size_t getDay01_part01(std::vector<std::string> &tokens);
  size_t getDay01_part02(std::vector<std::string> &tokens);
  safeRaports getDay02_part01(std::vector<std::string> &tokens);
  size_t getDay03_part01(std::vector<std::string> &tokens);
  size_t getDay04_part01(std::vector<std::string> &tokens);
  size_t getDay05_part01(PageVec &pages, RulesMap &rules);
  size_t getDay06_part01(PuzzleArray &puzzle, char obstacle, char guard);



 private:
 bool isRaportSafe(std::vector<int>& inRaport);

};


