/**
* @file WeightedSelection_test.cpp
* @brief Unit tests for the WeightedSelection class.
* @author Dominique LaSalle <dominique@solidlake.com>
* Copyright 2018
* @version 1
* @date 2018-08-23
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included
* in all copies or substantial portions of the Software.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
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
