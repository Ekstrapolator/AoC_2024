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
  }
  if (inputFile.peek() == std::ifstream::traits_type::eof()) {
    fprintf(stderr, "func::%s file is empty\n", __func__);
    std::terminate();

  }
  fileContent = std::string(std::istreambuf_iterator<char>(inputFile),
                            std::istreambuf_iterator<char>());
}

PuzzleArray InputManager::getStaticInput() {
  PuzzleArray puzzleArray{};
  int row{0};
  int col{0};
  for (auto c : fileContent)
  {
    if (c == '\n')
    {
    ++row;
    col = 0;
    continue;
    }
    puzzleArray.data.at(row).at(col) = c;
    ++col;
  }
  puzzleArray.rowMax = row + 1;
  puzzleArray.colMax = col;
  return puzzleArray;
};
