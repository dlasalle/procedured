/**
* @file Graph.cpp
* @brief Implementation of the Graph class.
* @author Dominique LaSalle <dominique@solidlake.com>
* Copyright 2018
* @version 1
* @date 2018-09-27
*/


#include "Graph.hpp"


namespace procedured
{


/******************************************************************************
* HELPER FUNCTIONS ************************************************************
******************************************************************************/

namespace
{

void remove_one_way_edge(
    Graph::vertex_type const source,
    Graph::vertex_type const dest,
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

void Graph::add_edge(
    vertex_type const vertex_a,
    vertex_type const vertex_b)
{
  m_edges.emplace(vertex_a, vertex_b);
  m_edges.emplace(vertex_b, vertex_a);
}

void Graph::remove_edge(
    vertex_type const vertex_a,
    vertex_type const vertex_b)
{
  remove_one_way_edge(vertex_a, vertex_b, &m_edges);
  remove_one_way_edge(vertex_b, vertex_a, &m_edges);
}

bool Graph::is_connected(
    vertex_type const vertex_a,
    vertex_type const vertex_b) const
{
  return m_edges.find(Edge(vertex_a, vertex_b)) != m_edges.cend();
}

std::vector<Graph::vertex_type> Graph::get_neighbors(
    vertex_type const vertex) const
{
  const Edge first_edge(vertex, 0);
  const Edge last_edge(vertex, m_num_vertices-1);
  const auto start = m_edges.lower_bound(first_edge);
  const auto end = m_edges.upper_bound(last_edge);

  std::vector<vertex_type> neighbors;
  for (auto iter = start; iter != end; ++iter) {
    neighbors.emplace_back(iter->dest());
  }

  return neighbors;
}



}
