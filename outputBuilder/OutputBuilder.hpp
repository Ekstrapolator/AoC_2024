//
// Created by wolek on 20.09.24.
//

#pragma once
#include <vector>
#include <string>

class OutputBuilder {
 public:
  OutputBuilder() = default;
  std::vector<std::pair<int, int>> getFirstAndLastNumber(std::vector<std::string> &tokens);
  size_t getDay01(std::vector<std::string> &tokens);

 private:

};


