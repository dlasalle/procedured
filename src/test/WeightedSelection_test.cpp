/**
* @file WeightedSelection_test.cpp
* @brief Unit tests for the WeightedSelection class.
* @author Dominique LaSalle <dominique@solidlake.com>
* Copyright 2018
* @version 1
* @date 2018-08-23
*/


#include "UnitTest.hpp"
#include "WeightedSelection.hpp"

#include <array>

namespace procedured
{


UNITTEST(WeightedSelection, Select10000Seed)
{
  WeightedSelection<int> w({ {0.1, 3}, {0.3, 2}, {0.5, 0}, {0.1, 1} });

  std::array<int, 4> hist;

  for (size_t i = 0; i < 10000; ++i) {
    int x = w.select(0, i);
    ++hist[x];
  }

  testLess(hist[0], 5500);
  testGreater(hist[0], 4500);

  testLess(hist[1], 1100);
  testGreater(hist[1], 900);

  testLess(hist[2], 3300);
  testGreater(hist[2], 2700);

  testLess(hist[3], 1100);
  testGreater(hist[3], 900);
}

}
