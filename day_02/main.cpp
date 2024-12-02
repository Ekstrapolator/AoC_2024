#include "fmt/format.h"
#include "InputManager.hpp"
#include "Tokenizer.hpp"
#include "../outputBuilder/OutputBuilder.hpp"

int main(int argv, const char** argc)
{
  Tokenizer tokenizer;
  InputManager inputOne("day_02/input_01.data");
  auto input = inputOne.getInput();
  auto lines = tokenizer.parse(input, "\n");
  OutputBuilder output;
  output.getDay02_part01(lines);

}
