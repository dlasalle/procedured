/**
* @file DepthFirstMazeGenerator_test.cpp
* @brief Unit tests for the DepthFirstMazeGenerator class.
* @author Dominique LaSalle <dominique@solidlake.com>
* Copyright 2018
* @version 1
* @date 2018-09-28
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
