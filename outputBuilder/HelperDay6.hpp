//
// Created by wolek on 17.04.25.
//

#pragma once

#include "2Dutils.hpp"
#include "InputManager.hpp"
#include "fmt/format.h"

class HelperDay6 {
 public:
  Guard getGuardPosition(const PuzzleArray &puzzle);
  bool guardInsideMaze(const PuzzleArray &puzzle, const Guard &guard);
  bool moveGuard(PuzzleArray &puzzle, Guard &guard, char obstacle);
  size_t numberOfVisitedFields(const PuzzleArray &puzzle);
};
