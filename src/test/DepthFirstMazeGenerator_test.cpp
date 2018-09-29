/**
* @file DepthFirstMazeGenerator_test.cpp
* @brief Unit tests for the DepthFirstMazeGenerator class.
* @author Dominique LaSalle <dominique@solidlake.com>
* Copyright 2018
* @version 1
* @date 2018-09-28
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


#include "DepthFirstMazeGenerator.hpp"
#include "UnitTest.hpp"

#include <cstddef>


namespace procedured
{


/******************************************************************************
* UNIT TESTS ******************************************************************
******************************************************************************/

UNITTEST(DepthFirstMazeGenerator, Generate5x5)
{
  Graph graph(25);

  for (size_t y = 0; y < 5; ++y) {
    for (size_t x = 0; x < 5; ++x) {
      for (int yi = -1; yi <= 1; ++yi) {
        if ((yi >= 0 || y > 0) && (yi <= 0 || y < 4) ) {
          for (int xi = -1; xi <= 1; ++xi) {
            if ((xi >= 0 || x > 0) && (xi <= 0 || x < 4) ) {
              if ((yi != 0 && xi == 0) || (yi == 0 && xi != 0)) {
                graph.add_edge(y*5+x, (y+yi)*5+(x+xi));
              }
            }
          }
        }
      }
    }
  }

  DepthFirstMazeGenerator gen(0);

  Graph tree = gen.generate(&graph);

  testEqual(tree.num_vertices(), graph.num_vertices());
  testEqual(tree.num_edges(), tree.num_vertices()-1);
}


}
