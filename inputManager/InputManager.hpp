//
// Created by wolek on 16.09.24.
//
#pragma once
#include <string>
#include <array>

typedef std::array<std::array<char, 1024>, 1024> PuzzleArray;

class InputManager {
 public:
  explicit InputManager(std::string filePath);
  std::string getInput() { return fileContent; };
  PuzzleArray getStaticInput();
 private:
  std::string fileContent;
};

