//
// Created by wolek on 16.09.24.
//

#include "InputManager.hpp"
#include <fstream>

InputManager::InputManager(const std::string filePath) {
  std::ifstream inputFile(filePath);
  if (!inputFile.is_open()) {
    fprintf(stderr, "func::%s unable to open file\n", __func__);
    std::terminate();
  } else {
    fileContent = std::string(std::istreambuf_iterator<char>(inputFile),
                              std::istreambuf_iterator<char>());
  }
};