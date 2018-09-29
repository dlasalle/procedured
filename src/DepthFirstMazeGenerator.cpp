/**
* @file DepthFirstMazeGenerator.cpp
* @brief Implementation of the DepthFirstMazeGenerator.
* @author Dominique LaSalle <dominique@solidlake.com>
* Copyright 2018
* @version 1
* @date 2018-09-28
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
