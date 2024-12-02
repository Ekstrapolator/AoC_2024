//
// Created by wolek on 16.09.24.
//
#pragma once
#include <string>

class InputManager {
 public:
  explicit InputManager(std::string filePath);
  std::string getInput() { return fileContent; };
 private:
  std::string fileContent;
};

