#include "fmt/format.h"
#include "InputManager.hpp"
#include "Tokenizer.hpp"
#include "OutputBuilder.hpp"
#include <filesystem>
#include <regex>


int main(int argv, const char** argc)
{
  auto path = std::filesystem::current_path();
  fmt::print("Current path: {}\n", path.c_str());
  Tokenizer tokenizer;
  InputManager inputOne("input_01.data");
  auto input = inputOne.getInput();
  auto tokens = tokenizer.regParse(input, std::regex(R"(mul\(\d+,\d+\))"));

  OutputBuilder output;
  auto mulSum = output.getDay03_part01(tokens);
  fmt::print("All mul {}", mulSum);
}
