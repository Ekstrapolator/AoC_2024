//
// Created by wolek on 23.04.25.
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
  InputManager inputOne("day_07/input_01.data");
  auto lines = tokenizer.parse(std::move(inputOne.getInput()));
  Resoults resoults;
  EquationComponents components;

  tokenizer.day07parse(lines , resoults, components);


  OutputBuilder output;

}