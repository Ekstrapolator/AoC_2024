//
// Created by wolek on 16.09.24.
//

#include "fmt/format.h"
#include "InputManager.hpp"
#include "Tokenizer.hpp"
#include "OutputBuilder.hpp"

int main(int argv, const char** argc)
{
  Tokenizer tokenizerOne;
  Tokenizer tokenizerTwo;
  OutputBuilder output;

  InputManager inputOne("input_1.txt");
  std::string contentOne = inputOne.getInput();
  //tokens are privet member reference ?
  std::vector<std::string> tokensOne = tokenizerOne.parse(contentOne, "\n");
  size_t solutionOne = output.getDay01_part01(tokensOne);
  printf("Soluition one %zu\n", solutionOne);

  InputManager inputTwo("input_2.txt");
  std::string contentTwo = inputTwo.getInput();
  //tokens are privet member reference ?
  std::vector<std::string> tokensTwo = tokenizerTwo.parse(contentTwo, "\n");
  size_t solutionTwo = output.getDay01_part02(tokensTwo);
  printf("Soluition two %zu\n", solutionTwo);
}