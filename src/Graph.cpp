/**
* @file Graph.cpp
* @brief Implementation of the Graph class.
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

#include <cassert>


namespace procedured
{


/******************************************************************************
* HELPER FUNCTIONS ************************************************************
******************************************************************************/

namespace
{

void remove_one_way_edge(
    Graph::size_type const source,
    Graph::size_type const dest,
    std::set<Graph::Edge> * const edges)
{
  edges->erase(edges->lower_bound(Graph::Edge(source, dest)));
}

}


/******************************************************************************
* CONSTRUCTORS / DESTRUCTOR ***************************************************
******************************************************************************/

Graph::Graph(
    size_t const num_vertices) :
  m_num_vertices(num_vertices),
  m_edges()
{
  // do nothing
}


/******************************************************************************
* PUBLIC METHODS **************************************************************
******************************************************************************/

Graph::size_type Graph::num_vertices() const
{
  return m_num_vertices;
}


Graph::size_type Graph::num_edges() const
{
  assert(m_edges.size() % 2 == 0);
  return m_edges.size() / 2;
}


void Graph::add_edge(
    size_type const vertex_a,
    size_type const vertex_b)
{
  m_edges.emplace(vertex_a, vertex_b);
  m_edges.emplace(vertex_b, vertex_a);
}

void Graph::remove_edge(
    size_type const vertex_a,
    size_type const vertex_b)
{
  remove_one_way_edge(vertex_a, vertex_b, &m_edges);
  remove_one_way_edge(vertex_b, vertex_a, &m_edges);
}

bool Graph::is_connected(
    size_type const vertex_a,
    size_type const vertex_b) const
{
  return m_edges.find(Edge(vertex_a, vertex_b)) != m_edges.cend();
}

std::vector<Graph::size_type> Graph::get_neighbors(
    size_type const vertex) const
{
  const Edge first_edge(vertex, 0);
  const Edge last_edge(vertex, m_num_vertices-1);
  const auto start = m_edges.lower_bound(first_edge);
  const auto end = m_edges.upper_bound(last_edge);

  std::vector<size_type> neighbors;
  for (auto iter = start; iter != end; ++iter) {
    neighbors.emplace_back(iter->dest());
  }

  return neighbors;
}



}
