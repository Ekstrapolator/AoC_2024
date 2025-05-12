//
// Created by wolek on 17.09.24.
//
#pragma once
#include <vector>
#include <string>
#include <regex>
#include "fmt/format.h"

typedef std::map<int, std::vector<int>> RulesMap;
typedef std::vector<std::vector<int>> PageVec;
typedef std::vector<long long int> Resoults;
typedef std::vector<std::vector<long long int>> EquationComponents;


class Tokenizer {
 public:
  Tokenizer() = default;
  std::vector<std::string> parse(std::string &&text,
                                 std::string delimiters = "\n");
  std::vector<std::string> regParse(std::string &text, std::regex reg);
  void day05parse(std::vector<std::string> &lines, RulesMap &rules,
                  PageVec &pages);
  void day07parse(const std::vector<std::string> &lines, Resoults &resoults,
                  EquationComponents &components);

 private:
  std::vector<std::string> tokens;
};



