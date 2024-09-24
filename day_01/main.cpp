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

  InputManager input("testFile");
  std::string& content = input.getInput();

  std::vector<std::string>& tokens = tokenizer.parse(content, "\n");
  std::vector<std::pair<int,int>> numbers =  output.getFirstAndLastNumber(tokens);
}