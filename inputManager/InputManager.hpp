//
// Created by wolek on 16.09.24.
//
#pragma once
#include <string>

class InputManager {
 public:
  explicit InputManager(std::string filePath);
 private:
  std::string fileContent;
};

