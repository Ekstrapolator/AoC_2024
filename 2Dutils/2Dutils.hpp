//
// Created by wolek on 14.12.24.
//

#pragma once

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

struct Point
{
  int row;
  int col;
};
