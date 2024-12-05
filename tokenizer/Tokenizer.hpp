//
// Created by wolek on 17.09.24.
//
#pragma once
#include <vector>
#include <string>
#include <regex>

class Tokenizer {
 public:
  Tokenizer() = default;
  std::vector<std::string> parse(std::string& text, std::string delimiters);
  std::vector<std::string> regParse(std::string& text, std::regex reg);

 private:
  std::vector<std::string> tokens;
};


