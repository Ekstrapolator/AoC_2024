//
// Created by wolek on 16.09.24.
//

#include "fmt/format.h"


#include "InputManager.hpp"
#include "Tokenizer.hpp"
#include "OutputBuilder.hpp"

int main(int argv, const char** argc)
{
  Tokenizer tokenizer;
  OutputBuilder output;

  InputManager input("/home/wolek/CODE/cppCode/AoC_2024/day_01/input.txt");
  std::string& content = input.getInput();

  std::vector<std::string>& tokens = tokenizer.parse(content, "\n");

  size_t solution = output.getDay01(tokens);
  printf("Soluition one %zu\n", solution);
}