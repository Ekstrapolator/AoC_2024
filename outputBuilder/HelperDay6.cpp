//
// Created by wolek on 17.04.25.
//

#include "HelperDay6.hpp"

Guard HelperDay6::getGuardPosition(const PuzzleArray &puzzle) {
  for (int row{0}; row < puzzle.rowMax; row++) {
    for (int col{0}; col < puzzle.colMax; col++) {
      if (puzzle.data.at(row).at(col) == '^') {
        return Guard{row, col, GuardDirection::up};
      }
    }
  }
  return Guard{};
}

bool HelperDay6::guardInsideMaze(const PuzzleArray &puzzle,
                                 const Guard &guard) {
  if (guard.col <= puzzle.colMax && guard.row <= puzzle.rowMax &&
      guard.col >= 0 && guard.row >= 0) {
    return true;
  }
  return false;
}

bool HelperDay6::moveGuard(PuzzleArray &puzzle, Guard &guard, char obstacle) {
  switch (guard.direction) {
    case GuardDirection::up:
      if (guard.row - 1 >= 0) {
        if (puzzle.data.at(guard.row - 1).at(guard.col) != obstacle) {
          guard.row--;
          puzzle.data.at(guard.row).at(guard.col) = 'X';
          return true;
        }
        // change direction
        guard.direction = GuardDirection::right;
        return true;
      }
      // guard is outside map row is size_t and will overflow
      guard.row--;
      return false;

    case GuardDirection::down:
      if (guard.row + 1 <= puzzle.rowMax) {
        if (puzzle.data.at(guard.row + 1).at(guard.col) != obstacle) {
          guard.row++;
          puzzle.data.at(guard.row).at(guard.col) = 'X';
          return true;
        }
        guard.direction = GuardDirection::left;
        return true;
      }
      // guard is outside map
      guard.row++;
      return false;

    case GuardDirection::left:
      if (guard.col - 1 >= 0) {
        if (puzzle.data.at(guard.row).at(guard.col - 1) != obstacle) {
          guard.col--;
          puzzle.data.at(guard.row).at(guard.col) = 'X';
          return true;
        }
        guard.direction = GuardDirection::up;
        return true;
      }
      guard.col--;
      return false;

    case GuardDirection::right:
      if (guard.col + 1 <= puzzle.colMax) {
        if (puzzle.data.at(guard.row).at(guard.col + 1) != obstacle) {
          guard.col++;
          puzzle.data.at(guard.row).at(guard.col) = 'X';
          return true;
        }
        guard.direction = GuardDirection::down;
        return true;
      }
      guard.col++;
      return false;
    default:
      fmt::print("Wrong Guard direction \n");
      return false;
  }
}
size_t HelperDay6::numberOfVisitedFields(const PuzzleArray &puzzle) {
  size_t count{0};
  for (auto row{0}; row <  puzzle.rowMax; row++) {
    for (auto col{0}; col < puzzle.colMax; col++) {
      if (puzzle.data.at(row).at(col) == 'X') {
        count++;
      }
    }
  }
  return count;
}