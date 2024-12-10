//
// Created by wolek on 06.12.24.
//
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
  InputManager inputOne("day_04/input_01.data");
  auto input = inputOne.getInput();
  auto grid = tokenizer.parse(input, "\n");

  OutputBuilder output;
  auto mulSum = output.getDay04_part01(grid);
  fmt::print("Answer is: {}", 0xFF);
}
