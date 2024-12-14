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
}
PuzzleArray InputManager::getStaticInput() {
  PuzzleArray puzzleArray{};
  int row{0};
  int col{0};
  for (auto puzzle : fileContent)
  {
    if (puzzle == '\n')
    {
    ++row;
    col = 0;
    continue;
    }
    puzzleArray.at(row).at(col) = puzzle;
    ++col;
  }
  return puzzleArray;
};
