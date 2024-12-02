//
// Created by wolek on 17.09.24.
//
#pragma once
#include <vector>
#include <string>

class Tokenizer {
 public:
  Tokenizer() = default;
  std::vector<std::string> parse(std::string& text, std::string delimiters);

 private:
  std::vector<std::string> tokens;
};


