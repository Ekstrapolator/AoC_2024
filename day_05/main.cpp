//
// Created by wolek on 11.12.24.
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
  InputManager inputOne("day_05/input_01.data");
  auto input = inputOne.getInput();
  auto lines = tokenizer.parse(input, "\n");
  RulesMap rules;
  PageVec pages;
  tokenizer.day05parse(lines, rules, pages);


  OutputBuilder output;
  auto answer = output.getDay05_part01(pages,rules);
  fmt::print("Answer is: {}", answer);
}
