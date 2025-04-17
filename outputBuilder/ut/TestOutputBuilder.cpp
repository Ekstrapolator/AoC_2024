//
// Created by wolek on 17.04.25.
//
#include <bits/ranges_base.h>
#include <gtest/gtest.h>
#include "2Dutils.hpp"
#include "HelperDay6.hpp"
#include "InputManager.hpp"

InputManager inputOne("/home/wolek/work/cppPrograms/gitHubRepos/AoC_2024/outputBuilder/ut/input_01_test.data");

struct TestHelperDay6 : public ::testing::Test {
  PuzzleArray puzzleArray = inputOne.getStaticInput();
};



TEST_F(TestHelperDay6, testgetGuardPos){
  Guard expectedGuardPos{6,4,GuardDirection::up};
  HelperDay6 d6{};
  Guard guard = d6.getGuardPosition(puzzleArray);
  EXPECT_EQ(expectedGuardPos, guard);
}

TEST_F(TestHelperDay6, testguardInsideMaze){
  HelperDay6 d6{};
  Guard guardInside{6,4,GuardDirection::up};
  Guard guardOutsideLeft{-1, 0, GuardDirection::left};
  Guard guardOutsideRight{0, 12, GuardDirection::up};
  Guard guardOutsideDown{12, 9, GuardDirection::up};
  Guard guardOutsideUp{3, -1, GuardDirection::up};
  EXPECT_EQ(d6.guardInsideMaze(puzzleArray, guardInside), true);
  EXPECT_EQ(d6.guardInsideMaze(puzzleArray, guardOutsideLeft), false);
  EXPECT_EQ(d6.guardInsideMaze(puzzleArray, guardOutsideRight), false);
  EXPECT_EQ(d6.guardInsideMaze(puzzleArray, guardOutsideDown), false);
  EXPECT_EQ(d6.guardInsideMaze(puzzleArray, guardOutsideUp), false);
}

TEST_F(TestHelperDay6, testMoveGuard){
  HelperDay6 d6{};
  std::vector<Guard> outsideMap{{0,0,GuardDirection::up},{0,0,GuardDirection::left},
   {0,10,GuardDirection::right}, {10,10,GuardDirection::down}};

  for (Guard goutside : outsideMap) {
  bool insideMap = d6.moveGuard(puzzleArray, goutside, '#');
  EXPECT_EQ(insideMap, false);
  }
}

TEST_F(TestHelperDay6, testGuardTurnsOnObstacle){
  HelperDay6 d6{};
  std::vector<Guard> beforeTurn{{2,9,GuardDirection::up},{3,3,GuardDirection::left},
  {3,1,GuardDirection::right},{2,2,GuardDirection::down}};
  std::vector<Guard> afterTurn{{2,9,GuardDirection::right},{3,3,GuardDirection::up},
  {3,1,GuardDirection::down},{2,2,GuardDirection::left}};

  auto before = beforeTurn.begin();
  auto after = afterTurn.begin();

  while (before != beforeTurn.end() && after != afterTurn.end()) {
  bool insideMap = d6.moveGuard(puzzleArray, *before, '#');
  // EXPECT_EQ is not using overloaded comparator
  EXPECT_EQ(before->col,after->col);
  EXPECT_EQ(before->row,after->row);
  EXPECT_EQ(before->direction,after->direction);
  ++before;
  ++after;
  }
}