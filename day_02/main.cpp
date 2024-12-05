#include "fmt/format.h"
#include "InputManager.hpp"
#include "Tokenizer.hpp"
#include "OutputBuilder.hpp"
#include <filesystem>


int main(int argv, const char** argc)
{
  auto path = std::filesystem::current_path();
  fmt::print("Current path: {}\n", path.c_str());
  Tokenizer tokenizer;
  InputManager inputOne("input_01.data");
  auto input = inputOne.getInput();
  auto lines = tokenizer.parse(input, "\n");
  OutputBuilder output;
  safeRaports safe = output.getDay02_part01(lines);
  fmt::print("Safe reports count {}", safe);
}
