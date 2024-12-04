#include "fmt/format.h"
#include "InputManager.hpp"
#include "Tokenizer.hpp"
#include "OutputBuilder.hpp"

int main(int argv, const char** argc)
{
  Tokenizer tokenizer;
  InputManager inputOne("/home/wolek/CODE/cppCode/AoC_2024/day_02/input_1_test.data");
  auto input = inputOne.getInput();
  auto lines = tokenizer.parse(input, "\n");
  OutputBuilder output;
  safeRaports safe = output.getDay02_part01(lines);
  fmt::print("Safe reports count {}", safe);
}
