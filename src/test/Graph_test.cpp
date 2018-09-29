/**
* @file Graph_test.cpp
* @brief Unit tests for the Graph class.
* @author Dominique LaSalle <dominique@solidlake.com>
* Copyright 2018
* @version 1
* @date 2018-09-27
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

  std::vector<Graph::size_type> neighbors = g.get_neighbors(1);

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
