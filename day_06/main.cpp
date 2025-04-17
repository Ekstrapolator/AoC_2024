//
// Created by wolek on 14.12.24.
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
  InputManager inputOne("day_06/input_01.data");
  auto puzzleArray = inputOne.getStaticInput();


  OutputBuilder output;
  auto answer = output.getDay06_part01(puzzleArray, '#', '^');
  output.writeToFile(puzzleArray);
  fmt::print("Answer is: {}", answer);
}