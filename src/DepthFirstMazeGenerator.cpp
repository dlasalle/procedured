/**
* @file DepthFirstMazeGenerator.cpp
* @brief Implementation of the DepthFirstMazeGenerator.
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

#include <algorithm>

namespace procedured
{


/******************************************************************************
* TYPES ***********************************************************************
******************************************************************************/

namespace
{

using size_type = Graph::size_type;

}

/******************************************************************************
* CONSTRUCTORS / DESTRUCTOR ***************************************************
******************************************************************************/

DepthFirstMazeGenerator::DepthFirstMazeGenerator(
    uint32_t const seed) :
  m_rng(seed)
{
  // do nothing
}

/******************************************************************************
* PUBLIC METHODS **************************************************************
******************************************************************************/

Graph DepthFirstMazeGenerator::generate(
    Graph const * const graph)
{
  std::uniform_int_distribution<size_type> distribution( \
      0, graph->num_vertices()-1);

  size_t const num_vertices = graph->num_vertices();

  Graph tree(num_vertices);

  // generate a maze using
  // https://en.wikipedia.org/wiki/Maze_generation_algorithm#Depth-first_search

  std::vector<bool> back_tracked(num_vertices, false);
  std::vector<bool> connected(num_vertices, false);

  // pick a random vertex as our root
  size_type root = distribution(m_rng);

  connected[root] = true;
  size_type num_connected = 1;

  std::vector<size_type> neighbors;
  neighbors.reserve(num_vertices);

  size_type v = root;
  do {
    neighbors = graph->get_neighbors(v);
    std::shuffle(neighbors.begin(), neighbors.end(), m_rng);

    // find the first available neighbor.    
    bool path_found = false;
    for (size_type const neighbor : neighbors) {
      if (!connected[neighbor]) {
        tree.add_edge(v, neighbor);
        v = neighbor;
        connected[v] = true;
        ++num_connected;
        path_found = true;
        break;
      }
    }

    // go back until we find the first backtraced node
    if (!path_found) {
      neighbors = tree.get_neighbors(v);
      for (size_type const neighbor : neighbors) {
        if (!back_tracked[neighbor]) {
          back_tracked[v] = true;
          v = neighbor;
          break;
        }
      }
    }
  } while (num_connected < num_vertices);

  return tree;
}



}
