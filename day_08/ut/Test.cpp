//
// Created by wolek on 17.04.25.
//
#include <bits/ranges_base.h>
#include <gtest/gtest.h>
#include "2Dutils.hpp"
#include "InputManager.hpp"

InputManager input("/home/wolek/work/cppPrograms/gitHubRepos/AoC_2024/day_08/input_01_test.data");

struct TestDay7 : public ::testing::Test {
  auto puzzleArray = input.getInput();
};



TEST_F(TestDay7, testgetGuardPos){

  EXPECT_EQ(1, 1);
}

