//
// Created by wolek on 16.09.24.
//
#pragma once
#include <string>
#include <array>

struct PuzzleArray{
 std::array<std::array<char, 1024>, 1024> data;
  size_t rowMax;
  size_t colMax;
};

class InputManager {
 public:
  explicit InputManager(std::string filePath);
  std::string getInput() { return fileContent; };
  PuzzleArray getStaticInput();
 private:
  std::string fileContent;
};

