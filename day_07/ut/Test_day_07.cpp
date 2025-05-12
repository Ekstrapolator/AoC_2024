//
// Created by wolek on 17.04.25.
//
#include <bits/ranges_base.h>
#include <gtest/gtest.h>
#include "2Dutils.hpp"
#include "InputManager.hpp"
#include "Tokenizer.hpp"

InputManager input("/home/wolek/work/cppPrograms/gitHubRepos/AoC_2024/day_07/input_01_test.data");

struct TestDay7 : public ::testing::Test {
  // add shared data betwine tests
};



TEST_F(TestDay7, testResoultRegex){
  Tokenizer tokenizer;
  auto lines = tokenizer.parse(std::move(input.getInput()));
  Resoults resoults;
  EquationComponents components;
  tokenizer.day07parse(lines , resoults, components);

  Resoults expectedResoults = {190,    3267, 83,    156, 7290,
                               161011, 192,  21037, 292};
  EquationComponents expectedComponents = {
      {10, 19},     {81, 40, 27}, {17, 5},        {15, 6},        {6, 8, 6, 15},
      {16, 10, 13}, {17, 8, 14},  {9, 7, 18, 13}, {11, 6, 16, 20}};

  EXPECT_EQ(components, expectedComponents);
  EXPECT_EQ(resoults, expectedResoults);
}

