//
// Created by wolek on 14.12.24.
//

#pragma once
#include <cstddef>

enum Directions {
  up = 0,
  upRight = 1,
  right = 2,
  downRight = 3,
  down = 4,
  downLeft = 5,
  left = 6,
  upLeft = 7,
};

enum class GuardDirection {
  up = 0,
  down = 1,
  right = 2,
  left = 3,
};

struct Point {
  size_t row;
  size_t col;
};

struct Guard {
  int row;
  int col;
  GuardDirection direction;

  bool operator==(const Guard& other) const {
  return row == other.row && col == other.col && direction == other.direction;
  }
};