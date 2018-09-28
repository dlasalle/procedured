/**
* @file Graph_test.cpp
* @brief Unit tests for the Graph class.
* @author Dominique LaSalle <dominique@solidlake.com>
* Copyright 2018
* @version 1
* @date 2018-09-27
*/


#include "Graph.hpp"
#include "UnitTest.hpp"


namespace procedured
{


UNITTEST(Graph, GetNeighbors)
{
  Graph g(5);

  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(1, 2);
  g.add_edge(2, 3);
  g.add_edge(1, 3);
  g.add_edge(3, 4);

  std::vector<Graph::vertex_type> neighbors = g.get_neighbors(1);

  testEqual(neighbors.size(), 3U);
  testEqual(neighbors[0], 0U);
  testEqual(neighbors[1], 2U);
  testEqual(neighbors[2], 3U);
}

UNITTEST(Graph, IsConnected)
{
  Graph g(5);

  g.add_edge(0, 1);
  g.add_edge(0, 2);
  g.add_edge(1, 2);
  g.add_edge(2, 3);
  g.add_edge(1, 3);
  g.add_edge(3, 4);

  testTrue(g.is_connected(0,1));
  testTrue(g.is_connected(0,2));
  testTrue(g.is_connected(1,2));
  testTrue(g.is_connected(2,3));
  testTrue(g.is_connected(1,3));
  testTrue(g.is_connected(3,4));
}



}
